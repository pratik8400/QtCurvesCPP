#include "renderarea.h"
#include <QPaintEvent>
#include <QPainter>
#include <math.h>

RenderArea::RenderArea(QWidget *parent) :
    QWidget(parent),
    mBackgroundColor(0, 0, 255),
    mShapeColor(255, 255, 255),
    mShape(Astroid)
{
    on_shape_changed();
}

QPointF RenderArea::compute(float t){
    switch (mShape) {
    case Astroid:
        return compute_astroid(t);
        break;
    case Cycloid:
        return compute_cycloid(t);
        break;
    case Huygenscycloid:
        return compute_huygenscycloid(t);
        break;
    case Hypocycloid:
        return compute_hypocycloid(t);
        break;
    default:
        break;
    }
    return QPointF(0,0);
}


QSize RenderArea::minimumSizeHint() const
{
    return QSize(100,100);
}

QSize RenderArea::sizeHint() const
{
    return QSize(400,200);
}

QPointF RenderArea::compute_astroid(float t){
    float cos_t = cos(t);
    float sin_t = sin(t);
    float x = 2 * cos_t * cos_t * cos_t;
    float y = 2 * sin_t * sin_t * sin_t;
    return QPointF(x, y);
}

QPointF RenderArea::compute_cycloid(float t){
    float cos_t = cos(t);
    float sin_t = sin(t);
    float x = 2 * cos_t * cos_t * cos_t;
    float y = 2 * sin_t * sin_t * sin_t;
    return QPointF(x, y);
}
QPointF RenderArea::compute_huygenscycloid(float t){
    float cos_t = cos(t);
    float sin_t = sin(t);
    float x = 2 * cos_t * cos_t * cos_t;
    float y = 2 * sin_t * sin_t * sin_t;
    return QPointF(x, y);
}
QPointF RenderArea::compute_hypocycloid(float t){
    float cos_t = cos(t);
    float sin_t = sin(t);
    float x = 2 * cos_t * cos_t * cos_t;
    float y = 2 * sin_t * sin_t * sin_t;
    return QPointF(x, y);
}


void RenderArea::on_shape_changed(){
    switch (mShape) {
    case Astroid:
        mScale = 40;
        mIntervalLength = 2 * M_PI;
        mStepCount = 300;
        break;
    case Cycloid:
        break;
    case Huygenscycloid:
        break;
    case Hypocycloid:
        break;
    default:
        break;
    }
}

void RenderArea::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);


    painter.setBrush(mBackgroundColor);
    painter.setPen(mShapeColor);
    //Drawing area
    painter.drawRect(this->rect());

    QPoint center = this->rect().center();
    float intervalLength = 2 * M_PI;
    float scale = 40;
    float step = mIntervalLength/mStepCount;
    for (float t =0; t< mIntervalLength; t+=step){
        QPointF point = compute_astroid(t);
        QPoint pixel;
        pixel.setX(point.x()* mScale + center.x());
        pixel.setY(point.y()* mScale + center.y());
        painter.drawPoint(pixel);

    }
}
