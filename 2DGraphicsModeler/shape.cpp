#include "shape.h"

Shape::Shape():shapeId {0}, shapeType {"Empty"}, shapeDimensions {0},\

    penColor {Qt::black}, penWidth {0}, penStyle { Qt::NoPen},\
    penCapStyle {Qt::FlatCap}, penJoinStyle {Qt::MiterJoin},\

    textString {"Empty"}, textColor{Qt::black}, textAlignment {Qt::AlignLeft},\
    textPointSize {-1}, textFontFamily {"Comic Sans MS"},\
    textFontStyle {QFont::StyleNormal} , textFontWeight {QFont::Thin}
{}
