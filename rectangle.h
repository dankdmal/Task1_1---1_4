#pragma once
class Rectangle {
public:
	Rectangle();
	Rectangle(int leftBotPoint[], int rightTopPoint[]);
	Rectangle(int leftBotPoint[], int length, int width);
	int get_width();
	int get_length();
	int* get_leftBotPoint();
	int* get_leftTopPoint();
	int* get_rightBotPoint();
	int* get_rightTopPoint();
	int get_perimeter();
	int get_square();
	int get_numberOfRectangles();
	int get_totalSquare();
	double get_inCircleRadius();
	double get_circumCircleRadius();
	bool get_isSquare();
	bool checkPoint(int* pointxy);
	void changeRectangle(int* leftBotPoint, int* rightTopPoint);
	void changeRectangle(int* leftBotPoint, int length, int width);
	~Rectangle();

private:
	unsigned int length;
	unsigned int width;
	unsigned int square;
	int leftBotPoint[2];
	int rightTopPoint[2];
	static int numberOfRectangles;
	static int totalSquare;
};