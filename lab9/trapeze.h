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
	void Input() override;
	friend std::istream& operator >> (std::istream& is, Trapeze& obj);
	friend std::ostream& operator <<(std::ostream& os, const Trapeze& obj);
	virtual ~Trapeze();
private:
	size_t smaller_base;
	size_t bigger_base;
	size_t left_side;
	size_t right_side;
};
