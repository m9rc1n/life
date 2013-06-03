#include "client_ui.hpp"
#include "ui_client_ui.h"

Client_UI::Client_UI(common::Config *config, QMainWindow *parent) :
    QMainWindow(parent),
    config(config),
    ui(new Ui::Client_UI())
{
    ui->setupUi(this);

    pixmap = new QPixmap(config->getMapWidth()*10+10, config->getMapHeight()*10+10);

    client_thread = new client::Client(common::Config::getInstance());
    client_thread->start();

    imageLabel = new QLabel;
    imageLabel->setPixmap(*pixmap);
    imageLabel->setScaledContents(true);
    ui->scrollArea->setWidget(imageLabel);

    createActions();
    createMenus();
    createConnections();

    setWindowTitle(tr("Life! ------ Predators vs. Herbivores"));
    setCursor(Qt::CrossCursor);

    scaleFactor = 1.0;
}


Client_UI::~Client_UI()
{
    delete ui;
}

void Client_UI::zoomIn()
{
    scaleImage(1.25);
}

void Client_UI::zoomOut()
{
    scaleImage(0.8);
}

void Client_UI::normalSize()
{
    imageLabel->adjustSize();
    scaleFactor = 1.0;
}

void Client_UI::about()
{
    QMessageBox::about (this, tr("About Life!"),
            tr("<p>The <b>Life!</b></p>"
               "<p><b>How to use: </b></p>"
               "<p>Ctrl++ : <b> zoom in </b></p>"
               "<p>Ctrl+- : <b> zoom out </b></p>"
               "<p>Ctrl+S : <b> reset scale </b></p>"
               "<p>Ctrl+Q : <b> quit </b></p>"
               "<p>Ctrl+A : <b> about/help </b></p>"
               "<p>Ctrl+W : <b> about Qt </b></p>"
               "<p><b> Authors: </b>"
               "Michal Krawczak \n"
               "Marcin Urbanski</p>"));
}

void Client_UI::legend()
{
    QMessageBox::about (this, tr("Legend of Creatures"),
        "<img src=\":/images/legend.png\"><I>Legend</I>");
}

void Client_UI::updatePixmap(const QImage &image)
{
    *pixmap = QPixmap::fromImage(image);
    imageLabel->setPixmap(*pixmap);
}

void Client_UI::scaleImage(double factor)
{
    Q_ASSERT(imageLabel->pixmap());

    scaleFactor *= factor;
    imageLabel->resize(scaleFactor * imageLabel->pixmap()->size());

    adjustScrollBar(ui->scrollArea->horizontalScrollBar(), factor);
    adjustScrollBar(ui->scrollArea->verticalScrollBar(), factor);

    zoomInAct->setEnabled(scaleFactor < 4);
    zoomOutAct->setEnabled(scaleFactor > 0.56);
}

void Client_UI::adjustScrollBar(QScrollBar *scrollBar, double factor)
{
    scrollBar->setValue(int(factor * scrollBar->value()
                            + ((factor - 1) * scrollBar->pageStep()/2)));
}

void Client_UI::createConnections()
{
    connect(client_thread, SIGNAL(renderedImage(QImage)), this, SLOT(updatePixmap(QImage)));

    connect(client_thread, SIGNAL(toPopPre(int)), this, SLOT(updatePopPre(int)));
    connect(client_thread, SIGNAL(toPopHer(int)), this, SLOT(updatePopHer(int)));
    connect(client_thread, SIGNAL(toPopCop(int)), this, SLOT(updatePopCop(int)));
    connect(client_thread, SIGNAL(toPopCre(int)), this, SLOT(updatePopCre(int)));

    connect(client_thread, SIGNAL(toAvePreAge(double)), this, SLOT(updateAvePreAge(double)));
    connect(client_thread, SIGNAL(toAvePreEne(double)), this, SLOT(updateAvePreEne(double)));
    connect(client_thread, SIGNAL(toAvePreFec(double)), this, SLOT(updateAvePreFec(double)));
    connect(client_thread, SIGNAL(toAvePreAng(double)), this, SLOT(updateAvePreAng(double)));
    connect(client_thread, SIGNAL(toAvePreRad(double)), this, SLOT(updateAvePreRad(double)));
    connect(client_thread, SIGNAL(toAvePreSpe(double)), this, SLOT(updateAvePreSpe(double)));
    connect(client_thread, SIGNAL(toAvePreRep(double)), this, SLOT(updateAvePreRep(double)));
    connect(client_thread, SIGNAL(toAvePreHyd(double)), this, SLOT(updateAvePreHyd(double)));

    connect(client_thread, SIGNAL(toMaxPreRep(double)), this, SLOT(updateMaxPreRep(double)));
    connect(client_thread, SIGNAL(toMaxPreHyd(double)), this, SLOT(updateMaxPreHyd(double)));
    connect(client_thread, SIGNAL(toMaxPreAge(double)), this, SLOT(updateMaxPreAge(double)));
    connect(client_thread, SIGNAL(toMaxPreEne(double)), this, SLOT(updateMaxPreEne(double)));

    connect(client_thread, SIGNAL(toDiePreAge(double)), this, SLOT(updateDiePreAge(double)));

    connect(client_thread, SIGNAL(toAveHerAge(double)), this, SLOT(updateAveHerAge(double)));
    connect(client_thread, SIGNAL(toAveHerEne(double)), this, SLOT(updateAveHerEne(double)));
    connect(client_thread, SIGNAL(toAveHerFec(double)), this, SLOT(updateAveHerFec(double)));
    connect(client_thread, SIGNAL(toAveHerAng(double)), this, SLOT(updateAveHerAng(double)));
    connect(client_thread, SIGNAL(toAveHerRad(double)), this, SLOT(updateAveHerRad(double)));
    connect(client_thread, SIGNAL(toAveHerSpe(double)), this, SLOT(updateAveHerSpe(double)));
    connect(client_thread, SIGNAL(toAveHerRep(double)), this, SLOT(updateAveHerRep(double)));
    connect(client_thread, SIGNAL(toAveHerHyd(double)), this, SLOT(updateAveHerHyd(double)));

    connect(client_thread, SIGNAL(toMaxHerRep(double)), this, SLOT(updateMaxHerRep(double)));
    connect(client_thread, SIGNAL(toMaxHerHyd(double)), this, SLOT(updateMaxHerHyd(double)));
    connect(client_thread, SIGNAL(toMaxHerAge(double)), this, SLOT(updateMaxHerAge(double)));
    connect(client_thread, SIGNAL(toMaxHerEne(double)), this, SLOT(updateMaxHerEne(double)));

    connect(client_thread, SIGNAL(toDieHerAge(double)), this, SLOT(updateDieHerAge(double)));
}

void Client_UI::createActions()
{

    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcut(tr("Ctrl+Q"));
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

    zoomInAct = new QAction(tr("Zoom &In (25%)"), this);
    zoomInAct->setShortcut(tr("Ctrl++"));
    zoomInAct->setEnabled(true);
    connect(zoomInAct, SIGNAL(triggered()), this, SLOT(zoomIn()));

    zoomOutAct = new QAction(tr("Zoom &Out (25%)"), this);
    zoomOutAct->setShortcut(tr("Ctrl+-"));
    zoomOutAct->setEnabled(true);
    connect(zoomOutAct, SIGNAL(triggered()), this, SLOT(zoomOut()));

    normalSizeAct = new QAction(tr("&Normal Size"), this);
    normalSizeAct->setShortcut(tr("Ctrl+S"));
    normalSizeAct->setEnabled(true);
    connect(normalSizeAct, SIGNAL(triggered()), this, SLOT(normalSize()));

    aboutAct = new QAction(tr("&About"), this);
    aboutAct->setEnabled(true);
    aboutAct->setCheckable(true);
    aboutAct->setShortcut(tr("Ctrl+A"));
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

    legendAct = new QAction(tr("&Legend"), this);
    legendAct->setEnabled(true);
    legendAct->setShortcut(tr("Ctrl+L"));
    connect(legendAct, SIGNAL(triggered()), this, SLOT(legend()));

    simulationLAct = new QAction(tr("Speed Simulation &Low"), this);
    simulationLAct->setEnabled(true);
    simulationLAct->setCheckable(true);
    simulationLAct->setShortcut(tr("1"));
    connect(simulationLAct, SIGNAL(triggered()), this, SLOT(speedSimulationLow()));

    simulationMAct = new QAction(tr("Speed Simulation &Medium"), this);
    simulationMAct->setEnabled(true);
    simulationMAct->setCheckable(true);
    simulationMAct->setShortcut(tr("2"));
    connect(simulationMAct, SIGNAL(triggered()), this, SLOT(speedSimulationMedium()));

    simulationHAct = new QAction(tr("Speed Simulation &High"), this);
    simulationHAct->setEnabled(true);
    simulationHAct->setCheckable(true);
    simulationHAct->setShortcut(tr("3"));
    connect(simulationHAct, SIGNAL(triggered()), this, SLOT(speedSimulationHigh()));

    aboutQtAct = new QAction(tr("About &Qt"), this);
    aboutQtAct->setEnabled(true);
    aboutQtAct->setCheckable(true);
    aboutQtAct->setShortcut(tr("Ctrl+W"));
    connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

    showParametresAct = new QAction(tr("&Show Parametres"), this);
    showParametresAct->setEnabled(true);
    showParametresAct->setCheckable(true);
    showParametresAct->setShortcut(tr("Ctrl+P"));
    connect(showParametresAct, SIGNAL(triggered()), this, SLOT(showParametres()));

    this->addAction(zoomInAct);
    this->addAction(zoomOutAct);
    this->addAction(normalSizeAct);
    this->addAction(aboutAct);
    this->addAction(aboutQtAct);
    this->addAction(exitAct);
    this->addAction(simulationHAct);
    this->addAction(simulationMAct);
    this->addAction(simulationLAct);
    this->addAction(legendAct);
}

void Client_UI::speedSimulationHigh()
{
    config->setSimulationSpeed(simulation_speed(HIGH));
    simulationLAct->setChecked(false);
    simulationMAct->setChecked(false);
}


void Client_UI::speedSimulationLow()
{
    config->setSimulationSpeed(simulation_speed(LOW));
    simulationHAct->setChecked(false);
    simulationMAct->setChecked(false);
}

void Client_UI::speedSimulationMedium()
{
    config->setSimulationSpeed(simulation_speed(MEDIUM));
    simulationHAct->setChecked(false);
    simulationLAct->setChecked(false);
}

void Client_UI::createMenus()
{
    fileMenu = new QMenu(tr("&File"), this);
    fileMenu->addAction(exitAct);

    viewMenu = new QMenu(tr("&View"), this);
    viewMenu->addAction(zoomInAct);
    viewMenu->addAction(zoomOutAct);
    viewMenu->addAction(normalSizeAct);
    viewMenu->addSeparator();
    viewMenu->addAction(simulationLAct);
    viewMenu->addAction(simulationMAct);
    viewMenu->addAction(simulationHAct);
    viewMenu->addSeparator();
    viewMenu->addAction(showParametresAct);

    helpMenu = new QMenu(tr("&Help"), this);
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(aboutQtAct);
    helpMenu->addSeparator();
    helpMenu->addAction(legendAct);

    menuBar()->addMenu(fileMenu);
    menuBar()->addMenu(viewMenu);
    menuBar()->addMenu(helpMenu);
}

void Client_UI::showParametres()
{
    if(config->getShowCreaturesParametres())
    {
        config->setShowCreaturesParametres(false);
    }
    else
    {
        config->setShowCreaturesParametres(true);
    }
}

void Client_UI::updatePopCre(int update)
{
    ui->pop_cre->display(update);
}

void Client_UI::updatePopHer(int update)
{
    ui->pop_her->display(update);
}

void Client_UI::updatePopPre(int update)
{
    ui->pop_pre->display(update);
}

void Client_UI::updatePopCop(int update)
{
    ui->pop_cop->display(update);
}

void Client_UI::updatePopTot()
{
    ui->pop_tot->display(common::Config::getInstance()->getObjectsCounter());
}

void Client_UI::updatePopSle(int update)
{
    ui->pop_sle->display(update);
}

void Client_UI::updateAveHerAge(double update)
{
    ui->ave_her_age->display(update);
}

void Client_UI::updateAveHerAng(double update)
{
    ui->ave_her_ang->display(update);
}

void Client_UI::updateAveHerEne(double update)
{
    ui->ave_her_ene->display(update);
}

void Client_UI::updateAveHerFec(double update)
{
    ui->ave_her_fec->display(update);
}

void Client_UI::updateAveHerHyd(double update)
{
    ui->ave_her_hyd->display(update);
}

void Client_UI::updateAveHerRad(double update)
{
    ui->ave_her_rad->display(update);
}

void Client_UI::updateAveHerRep(double update)
{
    ui->ave_her_rep->display(update);
}

void Client_UI::updateAveHerSpe(double update)
{
    ui->ave_her_spe->display(update);
}

void Client_UI::updateMaxHerAge(double update)
{
    ui->max_her_age->display(update);
}

void Client_UI::updateMaxHerEne(double update)
{
    ui->max_her_ene->display(update);
}

void Client_UI::updateMaxHerHyd(double update)
{
    ui->max_her_hyd->display(update);
}

void Client_UI::updateMaxHerRep(double update)
{
    ui->max_her_rep->display(update);
}

void Client_UI::updateDieHerAge(double update)
{
    ui->die_her_age->display(update);
}

void Client_UI::updateAvePreAge(double update)
{
    ui->ave_pre_age->display(update);
}

void Client_UI::updateAvePreAng(double update)
{
    ui->ave_pre_ang->display(update);
}

void Client_UI::updateAvePreEne(double update)
{
    ui->ave_pre_ene->display(update);
}

void Client_UI::updateAvePreFec(double update)
{
    ui->ave_pre_fec->display(update);
}

void Client_UI::updateAvePreHyd(double update)
{
    ui->ave_pre_hyd->display(update);
}

void Client_UI::updateAvePreRad(double update)
{
    ui->ave_pre_rad->display(update);
}

void Client_UI::updateAvePreRep(double update)
{
    ui->ave_pre_rep->display(update);
}

void Client_UI::updateAvePreSpe(double update)
{
    ui->ave_pre_spe->display(update);
}

void Client_UI::updateMaxPreAge(double update)
{
    ui->max_pre_age->display(update);
}

void Client_UI::updateMaxPreEne(double update)
{
    ui->max_pre_ene->display(update);
}

void Client_UI::updateMaxPreHyd(double update)
{
    ui->max_pre_hyd->display(update);
}

void Client_UI::updateMaxPreRep(double update)
{
    ui->max_pre_rep->display(update);
}

void Client_UI::updateDiePreAge(double update)
{
    ui->die_pre_age->display(update);
}
