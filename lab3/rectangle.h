#ifndef _RECTANGLE_H
#define _RECTANGLE_H

#include <cstdlib>
#include <iostream>
#include "figure.h"

class Rectangle : public Figure {
public:
	Rectangle();
	Rectangle(std::istream &is);
	Rectangle(size_t length, size_t height);
	Rectangle(const Rectangle& orig);
	double Square() override;
	void Print() override;
	virtual ~Rectangle();
	friend std::istream& operator >>(std::istream& is, Rectangle& obj);
	friend std::ostream& operator <<(std::ostream& os, const Rectangle& obj);
	Rectangle& operator =(const Rectangle& obj);
	bool operator ==(const Rectangle& obj);
private:
	size_t length;
	size_t height;
};

#endif 
