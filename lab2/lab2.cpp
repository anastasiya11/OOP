#include "stdafx.h"
#include <iostream>
#include "array.h"
using namespace std;

int main()
{
	Rectangle *r = new Rectangle(4, 2);
	cin >> *r;
	TArray ta(5, r);
	cout << ta;
    return 0;
}
