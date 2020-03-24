#pragma once
#include "rectangle.h"

class InscribedCircle
{
public:
    InscribedCircle(Rectangle* rect);
    double get_InCircleRadius();

private:
    double inCircleRadius;
};