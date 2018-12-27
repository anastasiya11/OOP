#include "stdafx.h"
#include "rhombus.h"
#include <cmath>
#define PI 3.14159265


Rhombus::Rhombus() : Rhombus(0, 0) {
}
Rhombus::Rhombus(size_t side_dimension, size_t angle) {
	side = side_dimension;
	if (smaller_angle > 180) {
		smaller_angle %= 180;
	}
	if (smaller_angle > 90) {
		smaller_angle = 180 - smaller_angle;
	}
	std::cout << "Rhombus created: " << side << ", " << smaller_angle << std::endl;
}
Rhombus::Rhombus(std::istream &is) {
	is >> side;
	is >> smaller_angle;
	if (smaller_angle > 180) {
		smaller_angle %= 180;
	}
	if (smaller_angle > 90) {
		smaller_angle = 180 - smaller_angle;
	}
}
Rhombus::Rhombus(const Rhombus& orig) {
	std::cout << "Rhombus copy created" << std::endl;
	side = orig.side;
	smaller_angle = orig.smaller_angle;
}
double Rhombus::Square() {
	return (double)(side * side * (double)sin(smaller_angle * (PI/ 180)));
}
void Rhombus::Print() {
	std::cout << "side = " << side << ", smaller_angle = " << smaller_angle << std::endl;
}
Rhombus::~Rhombus() {
	std::cout << "Rhombus deleted" << std::endl;
}
