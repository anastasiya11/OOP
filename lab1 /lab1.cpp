#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include "rectangle.h"
#include "trapeze.h"
#include "rhombus.h"
using namespace std;


int main()
{
	cout << "Rectangle: length, height :" << endl;
	Rectangle * prectangle = new Rectangle(cin);
	(*prectangle).Print();
	cout << "Square = " <<prectangle->Square() << endl;
	cout << "Rhombus: side, angle" << endl;
	Rhombus *prhombus = new Rhombus(cin);
	(*prhombus).Print();
	cout << "Square = " << prhombus->Square() << endl;
	cout << "Trapeze: smaller_base, bigger_base, left_side, right_side" << endl;
	Trapeze *ptrapeze = new Trapeze(cin);
	cout << "Square = " << ptrapeze->Square() << endl;
	(*ptrapeze).Print();
	system("pause");
    return 0;
}
