#include "client_ui.hpp"
#include "ui_client_ui.h"

Client_UI::Client_UI(common::Config *config, QMainWindow *parent) :
    QMainWindow(parent),
    config(config),
    ui(new Ui::Client_UI())
{
  ui->setupUi(this);

  pixmap = new QPixmap(config->map_width*10, config->map_height*10);

  client_thread = new client::Client(common::Config::getInstance());
  connect(client_thread, SIGNAL(renderedImage(QImage,double)), this, SLOT(updatePixmap(QImage,double)));

  imageLabel = new QLabel;
  imageLabel->setPixmap(*pixmap);
  ui->scrollArea->setWidget(imageLabel);

  createActions();

  setWindowTitle(tr("Predators vs. Herbivores"));
  setCursor(Qt::CrossCursor);

  scaleFactor = 1.0;

  imageLabel->setScaledContents(true);

  printAct->setEnabled(true);
  fitToWindowAct->setEnabled(true);
  updateActions();

  if (!fitToWindowAct->isChecked())
      imageLabel->adjustSize();
}


Client_UI::~Client_UI()
{
    delete ui;
}

void Client_UI::drawLabel()
{
}

void Client_UI::paintEvent(QPaintEvent *e /* event */)
{
}

void Client_UI::print(){}
void Client_UI::zoomIn()
{
    scaleImage(1.1);
}

void Client_UI::zoomOut()
{
    scaleImage(0.9);
}

void Client_UI::normalSize()
{
    imageLabel->adjustSize();
    scaleFactor = 1.0;
}

void Client_UI::fitToWindow()
{
    bool fitToWindow = fitToWindowAct->isChecked();
    ui->scrollArea->setWidgetResizable(fitToWindow);
    if (!fitToWindow) {
        normalSize();
    }
    updateActions();
}

void Client_UI::about()
{
    QMessageBox::about(this, tr("About Image Viewer"),
            tr("<p>The <b>Image Viewer</b> example shows how to combine QLabel "
               "and QScrollArea to display an image. QLabel is typically used "
               "for displaying a text, but it can also display an image. "
               "QScrollArea provides a scrolling view around another widget. "
               "If the child widget exceeds the size of the frame, QScrollArea "
               "automatically provides scroll bars. </p><p>The example "
               "demonstrates how QLabel's ability to scale its contents "
               "(QLabel::scaledContents), and QScrollArea's ability to "
               "automatically resize its contents "
               "(QScrollArea::widgetResizable), can be used to implement "
               "zooming and scaling features. </p><p>In addition the example "
               "shows how to use QPainter to print an image.</p>"));
}

void Client_UI::resizeEvent(QResizeEvent * /* event */)
{
    client_thread->render(0, 0, 1, size());
}

void Client_UI::updatePixmap(const QImage &image, double scaleFactor)
{
    *pixmap = QPixmap::fromImage(image);
    imageLabel->setPixmap(*pixmap);
}

void Client_UI::updateActions()
{
    zoomInAct->setEnabled(!fitToWindowAct->isChecked());
    zoomOutAct->setEnabled(!fitToWindowAct->isChecked());
    normalSizeAct->setEnabled(!fitToWindowAct->isChecked());
}

void Client_UI::scaleImage(double factor)
{
    Q_ASSERT(imageLabel->pixmap());

    scaleFactor *= factor;
    imageLabel->resize(scaleFactor * imageLabel->pixmap()->size());

    adjustScrollBar(ui->scrollArea->horizontalScrollBar(), factor);
    adjustScrollBar(ui->scrollArea->verticalScrollBar(), factor);

    zoomInAct->setEnabled(scaleFactor < 2.5);
    zoomOutAct->setEnabled(scaleFactor > 0.56);

    // client_thread->render(0, 0, scaleFactor, size());
}

void Client_UI::adjustScrollBar(QScrollBar *scrollBar, double factor)
{
    scrollBar->setValue(int(factor * scrollBar->value()
                            + ((factor - 1) * scrollBar->pageStep()/2)));
}

void Client_UI::createActions()
{

    printAct = new QAction(tr("&Print..."), this);
    printAct->setShortcut(tr("Ctrl+P"));
    printAct->setEnabled(false);
    connect(printAct, SIGNAL(triggered()), this, SLOT(print()));

    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcut(tr("Ctrl+Q"));
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

    zoomInAct = new QAction(tr("Zoom &In (25%)"), this);
    zoomInAct->setShortcut(tr("Ctrl++"));
    zoomInAct->setEnabled(false);
    connect(zoomInAct, SIGNAL(triggered()), this, SLOT(zoomIn()));

    zoomOutAct = new QAction(tr("Zoom &Out (25%)"), this);
    zoomOutAct->setShortcut(tr("Ctrl+-"));
    zoomOutAct->setEnabled(false);
    connect(zoomOutAct, SIGNAL(triggered()), this, SLOT(zoomOut()));

    normalSizeAct = new QAction(tr("&Normal Size"), this);
    normalSizeAct->setShortcut(tr("Ctrl+S"));
    normalSizeAct->setEnabled(false);
    connect(normalSizeAct, SIGNAL(triggered()), this, SLOT(normalSize()));

    fitToWindowAct = new QAction(tr("&Fit to Window"), this);
    fitToWindowAct->setEnabled(false);
    fitToWindowAct->setCheckable(true);
    fitToWindowAct->setShortcut(tr("Ctrl+F"));
    connect(fitToWindowAct, SIGNAL(triggered()), this, SLOT(fitToWindow()));

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
    this->addAction(fitToWindowAct);
    this->addAction(normalSizeAct);
    this->addAction(aboutAct);
    this->addAction(aboutQtAct);
    this->addAction(exitAct);
}

