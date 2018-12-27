#include "TArrayItem.h"

template<class T>
TArrayItem<T>::TArrayItem() : figure(nullptr)
{
	std::cout << "TArrayItem created" << std::endl;
}



template<class T>
TArrayItem<T>::TArrayItem(const std::shared_ptr<T>& figure) : figure(figure)
{
	std::cout << "TArrayItem created" << std::endl;
}


template<class T>
void TArrayItem<T>::SetPtr(const std::shared_ptr<T>& my_figure)
{
	figure = my_figure;
}


template<class T>
double TArrayItem<T>::Square()
{
	return figure->Square();
}


template<class T>
TArrayItem<T>::~TArrayItem()
{
	std::cout << "TArrayItem deleted" << std::endl;
}

template<class A>
std::ostream& operator<<(std::ostream& os, const TArrayItem<A>& obj)
{
	if (obj.figure) {
		obj.figure->Print();
	}
	return os;
}


template<class A>
std::istream& operator>>(std::istream& is, const TArrayItem<A>& obj)
{
	if (obj.figure) {
		obj.figure->Input();
	}
	return is;
}

#include "figure.h"
template class TArrayItem<Figure>;
template std::ostream& operator<<(std::ostream& os, const TArrayItem<Figure>& obj);
/*
#include "rectangle.h"
#include "rhombus.h"
#include "trapeze.h"
template class TArrayItem<Rectangle>;
template std::ostream& operator<<(std::ostream& os, const TArrayItem<Rectangle>& obj);
template class TArrayItem<Rhombus>;
template std::ostream& operator<<(std::ostream& os, const TArrayItem<Rhombus>& obj);
template class TArrayItem<Trapeze>;
template std::ostream& operator<<(std::ostream& os, const TArrayItem<Trapeze>& obj);
*/
