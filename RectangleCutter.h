#pragma once
#include "Rectangle.h"

class RectangleCutter :  public Rectangle {
public:
	RectangleCutter(int* leftBotPoint, int* rightTopPoint);
	Rectangle* cut_rectangle(Rectangle& rectangle);
};