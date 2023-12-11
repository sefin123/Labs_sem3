#include "DrawingArea.h"
#include "CreateFunctions.h"

#include "ImageSizeException.h"

#include "DrawCommand.h"
#include "ResizeCommand.h"
#include "FlipCommand.h"
#include "CorrectionCommand.h"
#include "FiltraringCommand.h"


namespace Draw
{

const QSize DrawingArea::_startSize(1920,1080);
const QSize DrawingArea::_maxSize(5000,5000);

DrawingArea::DrawingArea(QUndoStack *undoStack, QWidget *parent) :
    QWidget(parent),
    _undoStack(undoStack),
    _penWidth(5),
    _penColor(Qt::black),
    _currentShape("1")

{
    const QImage _image = QImage();
    isDrawing = false;
    ResizeCommand(this, &this->_image, _startSize).redo();
}

DrawingArea::~DrawingArea()
{
}

bool DrawingArea::isModified()
{
    return !(this->_undoStack->isClean());
}

void DrawingArea::resizeIamge(const QSize newSize)
{
    this->_undoStack->push(new ResizeCommand(this, &this->_image,
                                             newSize));
}

void DrawingArea::flip(bool horizontal, bool vertical)
{
    this->_undoStack->push(new FlipCommand(this, &this->_image,
                                           horizontal, vertical));
}

void DrawingArea::medianFilter(const int ratio)
{
    this->_undoStack->push(new FiltraringCommand(this, &this->_image,
                                                 ratio));
}

void DrawingArea::gammaCorrection(const double gamma)
{
    this->_undoStack->push(new CorrectionCommand(this, &this->_image,
                                                 gamma));
}

void DrawingArea::createNewImage()
{
    ResizeCommand(this, &this->_image, _startSize).redo();
    this->_image.fill(Qt::white);

    this->_undoStack->clear();
}

bool DrawingArea::openImage(const QString &fileName)
{
    QImage loadedImage;
    if (!loadedImage.load(fileName))
        return false;

    const QSize newSize = loadedImage.size();

    if(newSize.width() > this->_maxSize.width() ||
        newSize.height() > this->_maxSize.height())
        throw ImageSizeException("Bad image resolution!");

    this->_image = loadedImage.convertToFormat(QImage::Format_ARGB32);

    ResizeCommand(this, &this->_image, newSize).redo();
    this->_undoStack->clear();

    return true;
}

bool DrawingArea::saveImage(const QString &fileName, const char *fileFormat)
{
    if (this->_image.save(fileName, fileFormat))
    {
        this->_undoStack->clear();
        return true;
    }
    else
        return false;
}

void DrawingArea::setPenColor(const QColor &newColor)
{
    this->_penColor = newColor;
}

void DrawingArea::setPenWidth(int newWidth)
{
    this->_penWidth = newWidth;
}

void DrawingArea::setCreatePen()
{
    this->_currentShape = "pen";
}

void DrawingArea::setCreateEllipse()
{
    this->_currentShape = "ellipse";
}

void DrawingArea::setCreateRectangle()
{
    this->_currentShape = "rectangle";
}

void DrawingArea::setCreateLine()
{
    this->_currentShape = "ColorPicker";
}

void DrawingArea::setCreateEraser()
{
    this->_currentShape = "pen";
    this->_oldPenColor = this->_penColor;
    this->_penColor = Qt::white;
    this->_isEraser = true;
}

void DrawingArea::setCreateFilledShape()
{
    this->_currentShape = "filledShape";
}

QColor DrawingArea::getPenColor()
{
    return this->_penColor;
}

int DrawingArea::getPenWidth()
{
    return this->_penWidth;
}

QSize DrawingArea::getImageSize()
{
    return this->_image.size();
}

void DrawingArea::drawEllipses(QMouseEvent *event)
{
    if(this->_isEraser)
    {
    this->_penColor = this->_oldPenColor;
        this->_isEraser = false;
    }
    QPainter painter(&this->_image);
    Ellipse ellipse(&this->_image, event->pos(), this->_penWidth, this->_penColor);
    ellipse.draw(painter);
    /*painter.setPen(QPen(this->getPenColor(), this->getPenWidth(),
                        Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));

    painter.drawEllipse(event->pos(), 100, 100);*/

    update();
}

void DrawingArea::drawRectangle(QMouseEvent *event)
{
    if(this->_isEraser)
    {
        this->_penColor = this->_oldPenColor;
        this->_isEraser = false;
    }
    QPainter painter(&this->_image);
    Rectangle rect(&this->_image, event->pos(), this->_penWidth, this->_penColor);
    rect.draw(painter);
//    painter.setPen(QPen(this->getPenColor(), this->getPenWidth(),
//                        Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));

//    painter.drawRect(event->pos().x(), event->pos().y(), 15, 15);

    update();
}

void DrawingArea::ColorPicker(QMouseEvent *event)
{
    this->_penColor = this->_image.pixelColor(event->pos().rx(), event->pos().rx());//<-color picker
}

void DrawingArea::fillShape(QMouseEvent *event)
{
    if(this->_isEraser)
    {
        this->_penColor = this->_oldPenColor;
        this->_isEraser = false;
    }
    FilledShape fillShape(&this->_image, event->pos(), this->_penColor);
    QPainter painter(&this->_image);
    fillShape.draw(painter);
    update();
}

void DrawingArea::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        if(this->_currentShape == "ellipse")
        {
            this->drawEllipses(event);
        }
        if(this->_currentShape == "rectangle")
        {
            return this->drawRectangle(event);
        }
        if(this->_currentShape == "ColorPicker")
        {
            return this->ColorPicker(event);
        }
        if(this->_currentShape == "filledShape")
        {
            return this->fillShape(event);
        }
        lastPoint = event->pos();
        this->isDrawing = true;
        _afterDrawingImage = _image.copy();
    }

}

void DrawingArea::drawMouseLine(const QPoint &endPoint)
{
    QPainter painter(&this->_image);
    painter.setPen(QPen(_penColor, _penWidth, Qt::SolidLine, Qt::RoundCap,
                        Qt::RoundJoin));

    painter.drawLine(lastPoint, endPoint);

    int rad = (_penWidth / 2) + 2;
    update(QRect(lastPoint, endPoint).normalized()
               .adjusted(-rad, -rad, +rad, +rad));
    lastPoint = endPoint;
}



void DrawingArea::mouseMoveEvent(QMouseEvent *event)
{
    if(this->isDrawing) {
        drawMouseLine(event->pos());
    }
}

void DrawingArea::mouseReleaseEvent(QMouseEvent *event)
{

    if(event->button() == Qt::LeftButton && this->isDrawing) {
        this->isDrawing = false;
        lastPoint = event->pos();
        update();

        this->_undoStack->push(new DrawCommand(this, &this->_image, _afterDrawingImage, _image.copy()));
    }
}

void DrawingArea::paintEvent(QPaintEvent *event)
{
    const QRect paintRect = event->rect();

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    painter.drawImage(paintRect, this->_image, paintRect);
}

} // namespace Draw
