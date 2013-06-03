#include "client_ui.hpp"
#include "ui_client_ui.h"

Client_UI::Client_UI(common::Config *config, QMainWindow *parent) :
    QMainWindow(parent),
    config(config),
    ui(new Ui::Client_UI())
{
    ui->setupUi(this);

    pixmap = new QPixmap(config->map_width*10+10, config->map_height*10+10);

    client_thread = new client::Client(common::Config::getInstance());
    client_thread->start();
    connect(client_thread, SIGNAL(renderedImage(QImage)), this, SLOT(updatePixmap(QImage)));
    connect(client_thread, SIGNAL(toPopPre(int)), this, SLOT(updatePopPre(int)));
    connect(client_thread, SIGNAL(toPopHer(int)), this, SLOT(updatePopHer(int)));
    connect(client_thread, SIGNAL(toPopCre(int)), this, SLOT(updatePopCre(int)));

    imageLabel = new QLabel;
    imageLabel->setPixmap(*pixmap);
    imageLabel->setScaledContents(true);
    ui->scrollArea->setWidget(imageLabel);

    createActions();
    createMenus();

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
    scaleImage(1.1);
}

void Client_UI::zoomOut()
{
    scaleImage(0.89);
}

void Client_UI::normalSize()
{
    imageLabel->adjustSize();
    scaleFactor = 1.0;
}

void Client_UI::about()
{
    QMessageBox::about(this, tr("About Life!"),
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

    aboutQtAct = new QAction(tr("About &Qt"), this);
    aboutQtAct->setEnabled(true);
    aboutQtAct->setCheckable(true);
    aboutQtAct->setShortcut(tr("Ctrl+W"));
    connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

    this->addAction(zoomInAct);
    this->addAction(zoomOutAct);
    this->addAction(normalSizeAct);
    this->addAction(aboutAct);
    this->addAction(aboutQtAct);
    this->addAction(exitAct);
}

void Client_UI::createMenus()
{
    fileMenu = new QMenu(tr("&File"), this);
    fileMenu->addAction(exitAct);

    viewMenu = new QMenu(tr("&View"), this);
    viewMenu->addAction(zoomInAct);
    viewMenu->addAction(zoomOutAct);
    viewMenu->addAction(normalSizeAct);

    helpMenu = new QMenu(tr("&Help"), this);
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(aboutQtAct);

    menuBar()->addMenu(fileMenu);
    menuBar()->addMenu(viewMenu);
    menuBar()->addMenu(helpMenu);
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

