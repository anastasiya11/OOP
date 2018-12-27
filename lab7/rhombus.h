#pragma once

#include <cstdlib>
#include <iostream>
#include "figure.h"

class Rhombus : public Figure {
public:
	Rhombus();
	Rhombus(std::istream &is);
	Rhombus(size_t side, size_t smaller_angle);
	Rhombus(const Rhombus& orig);
	double Square() override;
	void Print() override;
	void Input() override;
	friend std::istream& operator >> (std::istream& is, Rhombus& obj);
	friend std::ostream& operator <<(std::ostream& os, const Rhombus& obj);
	virtual ~Rhombus();
private:
	size_t side;
	size_t smaller_angle;
};
