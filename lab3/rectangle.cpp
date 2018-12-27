#include "rectangle.h"
#include <cmath>

Rectangle::Rectangle() : Rectangle(0, 0) {}

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
	std::cout << "Rectangle: length = " << length << ", height = " << height << std::endl;
}

Rectangle::~Rectangle() {
	std::cout << "Rectangle deleted" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Rectangle& obj) {
	os << "Rectangle: length = " << obj.length << ", height = " << obj.height << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, Rectangle& obj) {
	std::cout << "Enter <lenght> <height>\n";
	is >> obj.length >> obj.height;
	return is;
}

Rectangle& Rectangle :: operator =(const Rectangle& obj)
{
	length = obj.length;
	height = obj.height;
	return *this;
}

bool Rectangle :: operator ==(const Rectangle& obj)
{
	if (length == obj.length && height == obj.height) {
		return true;
	}
	return false;
}
