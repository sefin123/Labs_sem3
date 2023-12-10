#ifndef DRAWCOMMAND_H
#define DRAWCOMMAND_H

#include "Shape.h"

#include <QUndoCommand>
#include <QWidget>

namespace Draw
{

class DrawCommand : public QUndoCommand
{
public:
    virtual void undo() override;
    virtual void redo() override;

    explicit DrawCommand(QWidget *drawingArea, QImage *image, QImage _afterDrawingImage, QImage _beforeDrawingImage);
    ~DrawCommand();

private:
    QWidget *_drawingArea;
    QImage *_image;
    QImage _afterDrawingImage;
    QImage _beforeDrawingImage;
};

} // namespace Draw

#endif // DRAWCOMMAND_H
