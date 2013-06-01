#include "client_ui.hpp"
#include "ui_client_ui.h"

#include <QPainter>
#include <QKeyEvent>
#include <cmath>

const double DefaultCenterX = -0.637011f;
const double DefaultCenterY = -0.0395159f;
const double DefaultScale = 1;//0.00403897f;

const double ZoomInFactor = 0.8f;
const double ZoomOutFactor = 1 / ZoomInFactor;
const int ScrollStep = 20;

Client_UI::Client_UI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Client_UI())
{
  ui->setupUi(this);
  centerX = DefaultCenterX;
  centerY = DefaultCenterY;
  pixmapScale = DefaultScale;
  curScale = DefaultScale;

  client_thread = new client::Client(common::Config::getInstance());
  connect(client_thread, SIGNAL(renderedImage(QImage,double)), this, SLOT(updatePixmap(QImage,double)));

  setWindowTitle(tr("Predators vs. Herbivores"));
  setCursor(Qt::CrossCursor);
  resize(2000, 2000);
}


Client_UI::~Client_UI()
{
    delete ui;
}

void Client_UI::paintEvent(QPaintEvent * /* event */)
{
    QPainter painter(this);
    painter.fillRect(rect(), Qt::black);

    if (pixmap.isNull()) {
        painter.setPen(Qt::white);
        painter.drawText(rect(), Qt::AlignCenter, tr("Rendering initial image, please wait..."));
        return;
    }
    if (curScale == pixmapScale) {
        painter.drawPixmap(pixmapOffset, pixmap);
    } else {
        double scaleFactor = pixmapScale / curScale;
        int newWidth = int(pixmap.width() * scaleFactor);
        int newHeight = int(pixmap.height() * scaleFactor);
        int newX = pixmapOffset.x() + (pixmap.width() - newWidth) / 2;
        int newY = pixmapOffset.y() + (pixmap.height() - newHeight) / 2;

        painter.save();
        painter.translate(newX, newY);
        painter.scale(scaleFactor, scaleFactor);
        QRectF exposed = painter.matrix().inverted().mapRect(rect()).adjusted(-1, -1, 1, 1);
        painter.drawPixmap(exposed, pixmap, exposed);
        painter.restore();
    }
    QString text = tr("Use mouse wheel or the '+' and '-' keys to zoom. "
                      "Press and hold left mouse button to scroll.");
    QFontMetrics metrics = painter.fontMetrics();
    int textWidth = metrics.width(text);

    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor(0, 0, 0, 127));
    painter.drawRect((width() - textWidth) / 2 - 5, 0, textWidth + 10, metrics.lineSpacing() + 5);
    painter.setPen(Qt::white);
    painter.drawText((width() - textWidth) / 2, metrics.leading() + metrics.ascent(), text);
}

void Client_UI::resizeEvent(QResizeEvent * /* event */)
{
    client_thread->render(centerX, centerY, curScale, size());
}

void Client_UI::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Plus:
        zoom(ZoomInFactor);
        break;
    case Qt::Key_Minus:
        zoom(ZoomOutFactor);
        break;
    case Qt::Key_Left:
        std::cout << "LEFT" <<std::endl;
        scroll(-ScrollStep, 0);
        break;
    case Qt::Key_Right:
        scroll(+ScrollStep, 0);
        break;
    case Qt::Key_Down:
        scroll(0, -ScrollStep);
        break;
    case Qt::Key_Up:
        scroll(0, +ScrollStep);
        break;
    default:
        QWidget::keyPressEvent(event);
    }
}

void Client_UI::updatePixmap(const QImage &image, double scaleFactor)
{
    if (!lastDragPos.isNull())
        return;

    pixmap = QPixmap::fromImage(image);
    pixmapOffset = QPoint();
    lastDragPos = QPoint();
    pixmapScale = scaleFactor;
    update();
}

void Client_UI::zoom(double zoomFactor)
{
    curScale *= zoomFactor;
    update();
    client_thread->render(centerX, centerY, curScale, size());
}

void Client_UI::scroll(int deltaX, int deltaY)
{
    centerX += deltaX * curScale;
    centerY += deltaY * curScale;
    update();
    client_thread->render(centerX, centerY, curScale, size());
}
