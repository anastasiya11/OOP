#include "array.h"


const size_t ERR_NO_MEM = 1;
const size_t ERR_OK = 0;


template <class T, class TT>
void TArray<T, TT>::InsertSubitem(TT* value) {
	bool inserted = false;
	if (array != nullptr) {
		for (auto i : *this) {
			if (i->GetItemValue1()->Size() < 5) {
				i->GetItemValue1()->push(value);
				std::cout << "Array: Add Element in array:" << i->GetItemValue()->Size() <<std::endl;
				inserted = true;
			}
		}
	}
	/*if (!inserted) {
		std::cout << "Array: New array element created" << std::endl;
		std::shared_ptr<T> t_value = (std::shared_ptr<T>) new T();
		t_value->push(value);
		TArrayItem<T> *ti = new TArrayItem<T>(t_value);//
		ElementInsert(ti, GetNextFree());
	}*/
}


template <class T, class TT> 
void TArray<T,TT>::RemoveSubitem(int size) {
	std::cout << " ---------------------->" << std::endl;
	for (auto i : *this) {
		T tree;
		for (int j = 0; j < 5; ++j) {
			
			if (i->GetItemValue1()->bt[j] != nullptr) {
				if (i->GetItemValue1()->bt[j]->Square() > size) {
					tree.push(i->GetItemValue1()->bt[j]);
				}
			}
			i->GetItemValue1()->bt[j] = nullptr;
			
		}
		i->GetItemValue1()->size = 0;
		for (int j = 0; j < tree.size; ++j) {
			i->GetItemValue1()->push(tree.bt[j]);
		}
		//std::cout << "Doshlo\n";
		//i->GetItemValue1()->rebuild();
	}
	std::cout << "!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
}



template <class T, class TT>
TArray<T,TT>::TArray(size_t arrSize)
{
	size = arrSize;
	array = new TArrayItem<T>[arrSize + 1];

	freearr = new bool[arrSize + 1];
	for (int i = 0; i < arrSize + 1; ++i) {
		freearr[i] = true;
	}
}

template <class T, class TT>
int TArray<T, TT>::GetNextFree()
{
	for (int i = 0; i < size; ++i) {
		if (freearr[i] == true) {
			return i;
		}
	}
	return -1;
}

template <class T, class TT>
TArray<T,TT>::TArray(size_t arrSize, const TArrayItem<T> * initObj)
{
	size = arrSize;
	array = new TArrayItem<T>[arrSize];
	for (size_t i = 0; i < size; i++) {
		//array[i] = *initObj;
		//*(&(*array) + i) = *initObj;
	}
}


template <class T, class TT>
int TArray<T,TT>::Size()
{
	return size;
}


template <class T, class TT>
size_t TArray<T,TT>::ElementInsert(TArrayItem<T> * obj, size_t index)
{
	if (index >= size) {
		std::cout << "Index too high" << std::endl;
	}
	//for (size_t i = index; i < size - 1; ++i) {
	//	array[i + 1] = array[i];
	//}
	else {
		*(&(*array) + index) = *obj;
		freearr[index] = false;
		//array[index] = *obj;
	}
	return ERR_OK;
}


template <class T, class TT>
void TArray<T,TT>::ElementDelete(size_t index)
{
	//array[index].SetPtr(nullptr);
	(*(&(*array) + index)).SetPtr(nullptr);
	/*for (size_t i = index; i < size; ++i) {
		array[i] = array[i + 1];
		--size;
		array = (TArrayItem *)realloc(array, size * sizeof(TArrayItem));
	}*/
}


template <class T, class TT>
TArrayItem<T>& TArray<T,TT>::ElementGet(size_t index)
{
	return *(&(*array) + index);
//	return array[index];
}

template<class A,class B>
std::ostream& operator<< (std::ostream& os, const TArray<A, B>& arr)
{
	for (size_t i = 0; i < arr.size; ++i) {
		os << "Element " << i << ": " << std::endl << *(&(*arr.array) + i) << std::endl;
	}
	return os;
}

template <class T, class TT>
TArray<T,TT>::~TArray()
{
	//delete[] array;
	array = nullptr;
	std::cout << "Array deleted" << std::endl;
}

template <class T, class TT> TIterator<TArrayItem<T>, T> TArray<T,TT>::begin()
{
	return TIterator<TArrayItem<T>, T>(array);
}

template <class T, class TT> TIterator<TArrayItem<T>, T> TArray<T,TT>::end()
{
	//std::shared_ptr<TArrayItem<T>> a(&(this->ElementGet(size)));
	//return TIterator<TArrayItem<T>, T>(nullptr);
	return TIterator<TArrayItem<T>, T>(&array[size]);
}


#include "Figure.h"
#include "rhombus.h"
#include "trapeze.h"
#include "TArrayItem.h"
#include "figure.h"

/*
template class TArray<Figure>;
template std::ostream& operator<<(std::ostream& os, const TArray<Figure>& obj);
template class TArray<Rhombus>;
template std::ostream& operator<<(std::ostream& os, const TArray<Rhombus>& obj);
template class TArray<Trapeze>;
template std::ostream& operator<<(std::ostream& os, const TArray<Trapeze>& obj);
*/
template class TArray<TBinaryTree<Figure>, Figure>;
template std::ostream& operator<<(std::ostream& os, const TArray<TBinaryTree<Figure>, Figure>& obj);
