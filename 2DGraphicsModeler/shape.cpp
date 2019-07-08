#include "shape.h"

Shape::Shape():shapeId {0}, shapeType {"Empty"}, shapeDimensions {0},\

<<<<<<< Updated upstream
    penColor {Qt::black}, penWidth {0}, penStyle { Qt::NoPen},\
    penCapStyle {Qt::FlatCap}, penJoinStyle {Qt::MiterJoin},\
=======
Shape::~Shape(){}

ShapeType Shape::get_shape() const{
    return shape;
}
const QBrush& Shape::get_brush()const{
    return brush;
}
const QPen& Shape::get_pen()const{
    return pen;
}
//const Shape::QPencil& get_pencil()const{
//    return pencil;
//}

void Shape::set_shape(ShapeType shapeIn){
    shape=shapeIn;
}

void Shape::set_pen(Qt::GlobalColor , int penWidth, Qt::PenStyle, Qt::PenCapStyle, Qt::PenJoinStyle )
{

   pen.setColor(penColor);
   pen.setWidth(penWidth);
   pen.setStyle(penStyle);
   pen.setCapStyle(penCapStyle);
   pen.setJoinStyle(penJoinStyle);

}
//void set_pencil(Qt::GlobalColor);


void Shape::set_brush(Qt::GlobalColor, Qt::BrushStyle)
{
    brush.setColor(brushColor);
    brush.setStyle(brushStyle);
}

QPainter& Shape::get_qpainter()
{
    return qpainter;
}
//void default_style();
>>>>>>> Stashed changes

    textString {"Empty"}, textColor{Qt::black}, textAlignment {Qt::AlignLeft},\
    textPointSize {-1}, textFontFamily {"Comic Sans MS"},\
    textFontStyle {QFont::StyleNormal} , textFontWeight {QFont::Thin}
{}
