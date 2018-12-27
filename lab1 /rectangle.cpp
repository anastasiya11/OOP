#include "stdafx.h"
#include "rectangle.h"
#include <cmath>

Rectangle::Rectangle() : Rectangle(0, 0) {
}
Rectangle::Rectangle(size_t length_in, size_t height_in) : length(length_in), height(height_in) {
	std::cout << "Rectangle created: " << length << ", " << height << ", " << std::endl;
}
Rectangle::Rectangle(std::istream &is) {
	is >> length;
	is >> height;
}
Rectangle::Rectangle(const Rectangle& orig) {
	std::cout << "Rectangle copy created" << std::endl;
	length = orig.length;
	height = orig.height;
}
double Rectangle::Square() {
	return double(length * height);
}
void Rectangle::Print() {
	std::cout << "length = " << length << ", height = " << height << std::endl;
}
Rectangle::~Rectangle() {
	std::cout << "Rectangle deleted" << std::endl;
}
