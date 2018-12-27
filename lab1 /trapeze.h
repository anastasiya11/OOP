#pragma once
#include <cstdlib>
#include <iostream>
#include "figure.h"


class Trapeze : public Figure {
public:
	Trapeze();
	Trapeze(std::istream &is);
	Trapeze(size_t smaller_base, size_t bigger_base, size_t left_side, size_t right_side);
	Trapeze(const Trapeze& orig);
	double Square() override;
	void Print() override;
	virtual ~Trapeze();
private:
	size_t smaller_base;
	size_t bigger_base;
	size_t left_side;
	size_t right_side;
};
