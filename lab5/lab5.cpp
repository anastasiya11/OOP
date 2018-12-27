#include <iostream>
#include "array.h"
#include <string>
#include "figure.h"
#include "rectangle.h"
using namespace std;

int main()
{
	
	//array.ElementInsert(std::shared_ptr<Rectangle>(new Rectangle(1, 1)),0);
	//array.ElementInsert(std::shared_ptr<Rectangle>(new Rectangle(2, 2)),1);
	//array.ElementInsert(std::shared_ptr<Rectangle>(new Rectangle(3, 3)), 3);
	shared_ptr<Figure> qw = (shared_ptr<Rectangle>)new Rectangle(1,2);
	TArrayItem<Figure> we(qw);
	TArray<Figure> array(5);
	array.ElementInsert(&we, 0);
	shared_ptr<Figure> q2 = (shared_ptr<Rectangle>)new Rectangle(4, 5);
	TArrayItem<Figure> w2(q2);
	array.ElementInsert(&w2, 1);
	shared_ptr<Figure> q3 = (shared_ptr<Rectangle>)new Rectangle(6, 7);
	TArrayItem<Figure> w3(q3);
	array.ElementInsert(&w3, 2);
	TArrayItem<Figure> neww(we);
	//TIterator <TArrayItem<Figure>, Figure> ti(&neww);
	TIterator <TArrayItem<Figure>, Figure> iter(&neww);

	//cout << "\n Start \n";
	//ti = array.begin();
	//cout << **ti;
	//++ti;
	//cout << **ti;
	//++ti;
	//cout << **ti;
	//cout << "Finish \n\n";
	//++ti;
	//cout << **ti;
	//for()



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
				shared_ptr<Rectangle> rtt = (shared_ptr<Rectangle>) new Rectangle(*rt);
				cin >> *rtt;
				trectangle.SetPtr(rtt);
				arr.ElementInsert(&trectangle, index);
			}
			else if (kindOfFigure == 2) {
				cout << "Rhombus: ";
				shared_ptr<Rhombus> rbb = (shared_ptr<Rhombus>) new Rhombus(*rbb);
				cin >> *rbb;
				arr.ElementInsert(&trhombus, index);
			}
			else if (kindOfFigure == 3) {
				cout << "Trapeze: ";
				shared_ptr<Trapeze> trr = (shared_ptr<Trapeze>) new Trapeze(*trr);
				cin >> *trr;
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
			for (auto itere : arr) cout << *itere << endl;
			//cout << arr;
			break;
		case 'q':
			return 0;
		}
	}
	

	
    return 0;
}
