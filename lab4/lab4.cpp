#include <iostream>
#include "array.h"
#include <string>
#include "figure.h"
#include "rectangle.h"
using namespace std;

int main()
{
	shared_ptr<Rectangle> rt = (shared_ptr<Rectangle>)new Rectangle();
	shared_ptr<Rhombus> rb = (shared_ptr<Rhombus>)new Rhombus();
	shared_ptr<Trapeze> tr = (shared_ptr<Trapeze>)new Trapeze();
	cout << "Enter size of array " << endl;
	int arr_size, kindOfFigure;
	cin >> arr_size;
	TArray<Figure> arr(arr_size);
	
	
	TArrayItem<Figure> trectangle(rt);
	TArrayItem<Figure> trhombus(rb);
	TArrayItem<Figure> ttrapeze(tr);
	char choice = 'b';
	int index;
	cout << "a to add\nd to delete\ng to get\np to print\nq to quit\n";
	while (choice != 'q') {
		cout << "Enter your choice\n" << endl;
		cin >> choice;
		switch (choice) {
		case 'a':
			cout << "Enter the index to add" << endl;
			cin >> index;
			if (index >= arr.Size()) {
				cout << "Index to high" << endl;
				break;
			}
			cout << "What are you want to insert: 1 - rectangle , 2 - rhombus, 3 - trapeze\n";
			cin >> kindOfFigure;
			if (kindOfFigure == 1) {
				cout << "Rectangle: ";
				cin >> *rt;
				trectangle.SetPtr(rt);
				arr.ElementInsert(&trectangle, index);
			}
			else if (kindOfFigure == 2) {
				cout << "Rhombus: ";
				cin >> *rb;
				arr.ElementInsert(&trhombus, index);
			}
			else if (kindOfFigure == 3) {
				cout << "Trapeze: ";
				cin >> *tr;
				arr.ElementInsert(&ttrapeze, index);
			}
			else {
				cout << "Wrong choice\n";
			}
			break;
		case 'd':
			cout << "Enter the index to delete" << endl;
			cin >> index;
			if (index >= arr.Size()) {
				cout << "Index to high" << endl;
				break;
			}
			arr.ElementDelete(index);
			break;
		case 'g':
			cout << "Enter the index to get" << endl;
			cin >> index;
			if (index >= arr.Size()) {
				cout << "Index to high" << endl;
				break;
			}
			cout << arr.ElementGet(index);
			break;
		case 'p':
			cout << arr;
			break;
		case 'q':
			return 0;
		}
	}
	
	
	
    return 0;
}
