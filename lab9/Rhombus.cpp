#include "stdafx.h"
#include <iostream>
#include <cmath>
#include "Rhombus.h"

Rhombus::Rhombus() : Rhombus(0, 0)
{
}

Rhombus::Rhombus(double i, double j) : side_a(i), side_b(j)
{
	//std::cout << "Rhombus created: " << side_a << ", " << side_b << std::endl;
}

Rhombus::Rhombus(std::istream &is)
{
	is >> side_a;
	is >> side_b;
	if (side_a < 0 || side_b < 0) {
		std::cerr << "Error: sides must be >= 0." << std::endl;
		side_a = 0;
		side_b = 0;
	}
}

Rhombus::Rhombus(const Rhombus& orig)
{
	std::cout << "Rhombus copy created." << std::endl;
	side_a = orig.side_a;
	side_b = orig.side_b;
	if (side_a < 0 || side_b < 0) {
		std::cerr << "Error: sides must be >= 0." << std::endl;
		side_a = 0;
		side_b = 0;
	}
}

double Rhombus::square()
{
	return side_a * side_b / 2;
}

void Rhombus::print()
{
	std::cout << "Rhombus with diag a = " << side_a << " b = " << side_b;
}

Rhombus::~Rhombus()
{
	//std::cout << "Rhombus deleted." << std::endl;
}

std::ostream & operator<<(std::ostream & os, const Rhombus & right)
{
	os << "Rhombus with diagonal a = " << right.side_a << ", diagonal b = " << right.side_b;
	return os;
}
