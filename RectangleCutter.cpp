#include "RectangleCutter.h"

RectangleCutter::RectangleCutter(int* leftBotPoint, int* rightTopPoint) :Rectangle(leftBotPoint, rightTopPoint) {}

Rectangle* RectangleCutter::cut_rectangle(Rectangle& rectangle) {
	double leftBotPoint[2], rightTopPoint[2];
	for (int i = 0; i < 2; i++) {
		if (this->get_rightTopPoint()[i] <= rectangle.get_rightTopPoint()[i])
			rightTopPoint[i] = this->get_rightTopPoint()[i];
		else {
			if (this->get_leftBotPoint()[i] >= rectangle.get_rightTopPoint()[i])
				rightTopPoint[i] = this->get_leftBotPoint()[i];
			else
				rightTopPoint[i] = rectangle.get_rightTopPoint()[i];
		}
	
		if (this->get_rightTopPoint()[i] >= rectangle.get_leftBotPoint()[i])
			leftBotPoint[i] = rectangle.get_leftBotPoint()[i];
		else {
			if (this->get_leftBotPoint()[i] >= rectangle.get_leftBotPoint()[i])
				leftBotPoint[i] = this->get_leftBotPoint()[i];
			else
				leftBotPoint[i] = this->get_rightTopPoint()[i];
		}

		if ((this->get_rightTopPoint()[i] > rectangle.get_rightTopPoint()[i]) && (this->get_leftBotPoint()[i] > rectangle.get_rightTopPoint()[i])) {
			leftBotPoint[i] = this->get_rightTopPoint()[i];
			rightTopPoint[i] = this->get_rightTopPoint()[i];
		}
		else {
			if ((this->get_rightTopPoint()[i] < rectangle.get_leftBotPoint()[i]) && (this->get_leftBotPoint()[i] > rectangle.get_leftBotPoint()[i])) {
				leftBotPoint[i] = this->get_rightTopPoint()[i];
				rightTopPoint[i] = this->get_rightTopPoint()[i];
		}
	}
	return new Rectangle(leftBotPoint, rightTopPoint);
}