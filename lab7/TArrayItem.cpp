#include "TArrayItem.h"

template<class T>
TArrayItem<T>::TArrayItem() : figure(nullptr)
{
	std::cout << "TArrayItem created" << std::endl;
}


template<class T>
TArrayItem<T> * TArrayItem<T>::GetNext()
{
	//std::shared_ptr<TArrayItem<T>> &(*(figure)) + 1
	//std::shared_ptr<TArrayItem<T>> ptr(this + 1);
	return  this + 1;
}

template<class T>
void TArrayItem<T>::SetNext(std::shared_ptr<TArrayItem<T>>& nxt)
{
	//next = nxt;
}


template<class T>
std::shared_ptr<T> TArrayItem<T>:: GetItemValue() const
{
	return figure;
}

template<class T>
T* TArrayItem<T>::GetItemValue1() const
{
	return &(*figure);
}

template<class T>
void TArrayItem<T>::SetPtr1(T* figure1)
{
	figure = (std::shared_ptr<T>)figure1;
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


//template<class T>
//double TArrayItem<T>::Square()
//{
//	return figure->Square();
//}


template<class T>
TArrayItem<T>::~TArrayItem()
{
	std::cout << "TArrayItem deleted" << std::endl;
}

template<class A>
std::ostream& operator<<(std::ostream& os, const TArrayItem<A>& obj)
{
	if (obj.figure) {
		//obj.figure->Print();
		std::cout << *(obj.figure);
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


template <class T> TAllocationBlock
TArrayItem<T>::arrayitem_allocator(sizeof(TArrayItem<T>), 100);

template <class T>
void * TArrayItem<T>::operator new (size_t size) {
	return arrayitem_allocator.allocate();
}

template <class T>
void TArrayItem<T>::operator delete(void *p) {
	arrayitem_allocator.deallocate(p);
}




//#include "figure.h"
//template class TArrayItem<Figure>;
//template std::ostream& operator<<(std::ostream& os, const TArrayItem<Figure>& obj);

#include "binary_tree.h"
template class TArrayItem<TBinaryTree<Figure>>;
template std::ostream& operator<<(std::ostream& os, const TArrayItem<TBinaryTree<Figure>>& obj);

/*
#include "Figure.h"
#include "rhombus.h"
#include "trapeze.h"
template class TArrayItem<Figure>;
template std::ostream& operator<<(std::ostream& os, const TArrayItem<Figure>& obj);
template class TArrayItem<Rhombus>;
template std::ostream& operator<<(std::ostream& os, const TArrayItem<Rhombus>& obj);
template class TArrayItem<Trapeze>;
template std::ostream& operator<<(std::ostream& os, const TArrayItem<Trapeze>& obj);
*/
