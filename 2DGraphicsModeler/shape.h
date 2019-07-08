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
private:
<<<<<<< Updated upstream
=======
    QPainter& qpainter;

    QPaintDevice* device;

    //shapeDimensions must be inherited

>>>>>>> Stashed changes
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
