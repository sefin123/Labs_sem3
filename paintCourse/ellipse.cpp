#include "Ellipse.h"

namespace Draw
{

Ellipse::Ellipse(QImage *image, const QPoint &eventPoint, int penWidth, const QColor &penColor) :
    Shape(image, penWidth, penColor), _rectangle(eventPoint.x(), eventPoint.y(), 100 ,100)
{
}

Ellipse::~Ellipse()
{
}

void Ellipse::draw(QPainter &painter)
{
    if (!this->_rectangle.isNull())
    {
        painter.setPen(QPen(this->getPenColor(), this->getPenWidth(),
                            Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));

        painter.drawEllipse(this->_rectangle);
    }
}

void Ellipse::update(const QPoint &toPoint)
{
    this->_rectangle.setBottomRight(toPoint);
}

QRect Ellipse::rect()
{
    const int correction = this->getPenWidth() / 2 + 2;

    QRect shapeRect = this->_rectangle.normalized();
    shapeRect = shapeRect.adjusted(-correction, -correction,
                                   +correction, +correction);

    return shapeRect;
}

} // namespace Draw

