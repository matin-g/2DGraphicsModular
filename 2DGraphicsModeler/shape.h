#ifndef SHAPE_H
#define SHAPE_H
#include <string>
#include <Qt>
#include <QFont>
#include "vector.h"

class Shape
{
public:
    Shape();
    virtual ~Shape();
    const QBrush& get_brush()const;

    void set_shape(ShapeType shape);
    void set_pen(Qt::GlobalColor, int width, Qt:PenStyle, Qt::PPenCapStyle, Qt::PenJointStyle);
    void set_brush(Qt::GlobalColor, Qt::BrushStyle)

    void default_style();
    void draw_rect(int width, int height);

    virtual void draw(const int x, const int y);
protected:
    QPainter& get_qpainter();

private:
    QPainter& qpainter;

    int shapeId;
    ShapeType shape;
    QPen pen;
    QBrush brush;

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
