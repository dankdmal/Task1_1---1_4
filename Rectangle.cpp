#include "Rectangle.h"
#include <math.h>
#include <iostream>

int Rectangle::numberOfRectangles = 0;
int Rectangle::totalSquare = 0;

Rectangle::Rectangle() {
	this->leftBotPoint[0] = 2;
	this->leftBotPoint[1] = 0;
	this->width = 10;
	this->length = 5;
	this->square = width * length;
	totalSquare += square;
	numberOfRectangles++;
}

Rectangle::Rectangle(int leftBotPoint[], int rightTopPoint[]) {
	for (int i = 0; i < 2; i++) {
		this->leftBotPoint[i] = *(leftBotPoint + i);
		this->rightTopPoint[i] = *(rightTopPoint + i);
	}
	this->length = abs(rightTopPoint[1] - leftBotPoint[1]);
	this->width = abs(rightTopPoint[0] - leftBotPoint[0]);
	this->square = width * length;
	totalSquare += square;
	numberOfRectangles++;
}

Rectangle::Rectangle(int leftBotPoint[], int length, int width) {
	for (int i = 0; i < 2; i++)
		this->leftBotPoint[i] = *(leftBotPoint + i);
	this->length = length;
	this->width = width;
	this->rightTopPoint[0] += width;
	this->rightTopPoint[1] += length;
	this->square = width * length;
	totalSquare += square;
	numberOfRectangles++;
}

void Rectangle::changeRectangle(int* leftBotPoint, int* rightTopPoint) {
	if ((abs(rightTopPoint[0] - leftBotPoint[0]) != 0) || (abs(rightTopPoint[1] - leftBotPoint[1]) != 0)) {
		totalSquare -= this->get_square();
		for (int i = 0; i < 2; i++) {
			this->leftBotPoint[i] = leftBotPoint[i];
			this->rightTopPoint[i] = rightTopPoint[i];
		}
		this->length = abs(rightTopPoint[1] - leftBotPoint[1]);
		this->width = abs(rightTopPoint[0] - leftBotPoint[0]);
		this->square = width * length;
		totalSquare += square;
	}
	else std::cout << "Wrong points" << std::endl;
}

void Rectangle::changeRectangle(int* leftBotPoint, int length, int width) {
	if ((length != 0) || (width != 0)) {
		totalSquare -= this->get_square();
		for (int i = 0; i < 2; i++)
			this->leftBotPoint[i] = *(leftBotPoint + i);
		this->length = length;
		this->width = width;
		this->rightTopPoint[0] += width;
		this->rightTopPoint[1] += length;
		this->square = width * length;
		totalSquare += square;
		numberOfRectangles++;
	}
	else std::cout << "Wrong lenth or width" << std::endl;
}

int Rectangle::get_numberOfRectangles() {
	return numberOfRectangles;
}

int Rectangle::get_totalSquare() {
	return totalSquare;
}

int Rectangle::get_width() {
	return width;
}

int Rectangle::get_length() {
	return length;
}

int* Rectangle::get_leftBotPoint() {
	return leftBotPoint;
}

int* Rectangle::get_leftTopPoint() {
	return new int[2]{ this->leftBotPoint[0], this->rightTopPoint[1] };
}

int* Rectangle::get_rightBotPoint() {
	return new int[2]{ this->rightTopPoint[0], this->leftBotPoint[1] };
}

int* Rectangle::get_rightTopPoint() {
	return rightTopPoint;
}

int Rectangle::get_perimeter() {
	return 2 * (this->get_length() + this->get_width());
}

int Rectangle::get_square() {
	return square;
}

double Rectangle::get_inCircleRadius() {
	if (this->get_isSquare())
		return this->get_length() / 2;
	else
		return 0;
}

double Rectangle::get_circumCircleRadius() {
	return sqrt(this->get_length() * this->get_length() + this->get_width() * this->get_width()) / 2;
}

bool Rectangle::get_isSquare() {
	if (this->get_length() == this->get_width())
		return true;
	else
		return false;
}

bool Rectangle::checkPoint(int* pointxy) {
	if (pointxy[0] >= leftBotPoint[0] && pointxy[0] <= rightTopPoint[0])
		if (pointxy[1] >= leftBotPoint[1] && pointxy[1] <= rightTopPoint[1])
			return true;
	return false;
}

Rectangle::~Rectangle() {
	totalSquare -= width * length;
	numberOfRectangles--;
}