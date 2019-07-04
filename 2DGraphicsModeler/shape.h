#ifndef SHAPE_H
#define SHAPE_H
#include <string>
#include <Qt>
#include <QFont>
#include "vector.h"

class Shape
{
public:
    enum class ShapeType{noShape, Line, Polyline,Polygon, Rectangle, Ellipse, Text};
    
    const QBrush& getBrush() const;
    Shape();
    
private:
    int shapeId;
    std::string shapeType;
    vector<vector<int>> shapeDimensions;

    Qt::GlobalColor penColor;
    int penWidth;
    Qt::PenStyle penStyle;
    Qt::PenCapStyle penCapStyle;
    Qt::PenJoinStyle penJoinStyle;

    Qt::GlobalColor brushColor;
    Qt::BrushStyle brushStyle;

    std::string textString;
    Qt::GlobalColor textColor;
    Qt::AlignmentFlag textAlignment;
    int textPointSize;
    std::string textFontFamily;
    QFont::Style textFontStyle;
    QFont::Weight textFontWeight;
};

#endif // SHAPE_H
