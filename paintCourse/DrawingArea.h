#ifndef DRAW_H
#define DRAW_H

#include "Shape.h"


#include <qevent.h>
#include <QPainter>
#include <QUndoStack>
#include <QEvent>
#include <QWidget>

namespace Draw
{

class DrawingArea : public QWidget
{
    Q_OBJECT
public:
    bool isModified();

    void createNewImage();

    bool openImage(const QString &fileName);
    bool saveImage(const QString &fileName, const char *fileFormat);

    void setPenColor(const QColor &newColor);
    void setPenWidth(int newWidth);

    QColor getPenColor();
    int getPenWidth();
    QSize getImageSize();

    void resizeIamge(const QSize newSize);

    void flip(bool horizontal, bool vertical);
    void rotate(qreal deg);
    void toggleEraserMode();
    void drawEllipses(QMouseEvent *event);
    void drawRectangle(QMouseEvent *event);
    void ColorPicker(QMouseEvent *event);
    void fillShape(QMouseEvent *event);
    void medianFilter(const int ratio);
    void gammaCorrection(const double gamma);
    void drawMouseLine(const QPoint &endPoint);

    DrawingArea(QUndoStack *undoStack, QWidget *parent = 0);
    ~DrawingArea();

public slots:
    void setCreatePen();
    void setCreateEllipse();
    void setCreateRectangle();
    void setColorPicker();
    void setCreateEraser();
    void setCreateFilledShape();

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);

private:
    Shape::ShapePointer(*_createShape)(QImage*, const QPoint&,
                                        int, const QColor&);
private:
    QUndoStack *_undoStack;
    QImage _image;
    int _penWidth;
    QPoint lastPoint;
    QColor _penColor;
    QColor _oldPenColor;
    std::string  _currentShape;
    bool isDrawing;
    QPoint prev;
    QImage _trashImage;
    QImage _afterDrawingImage;
    bool _isEraser;

    static const QSize _startSize;
    static const QSize _maxSize;
};

} // namespace Draw

#endif //DRAW_H

