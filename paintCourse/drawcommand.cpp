#include "DrawCommand.h"

namespace Draw
{

DrawCommand::DrawCommand(QWidget *drawingArea, QImage *image, QImage afterDrawingImage, QImage beforeDrawingImage) :
    _drawingArea(drawingArea),
    _image(image),
    _afterDrawingImage(afterDrawingImage),
    _beforeDrawingImage(beforeDrawingImage)
{
}

void DrawCommand::undo()
{

    *this->_image = this->_afterDrawingImage;
    this->_drawingArea->update();
}

void DrawCommand::redo()
{
    *this->_image = this->_beforeDrawingImage;

    this->_drawingArea->update();

}

DrawCommand::~DrawCommand() {}

} // namespace Draw
