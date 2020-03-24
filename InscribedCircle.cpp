#include "InscribedCircle.h"

InscribedCircle::InscribedCircle(Rectangle* rectangle)
{
    this->inCircleRadius = rectangle->get_inCircleRadius;
}

double InscribedCircle::get_InCircleRadius()
{
    return inCircleRadius;
}