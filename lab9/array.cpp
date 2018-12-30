#include "array.h"
#include <future>
#include <iomanip>

const size_t ERR_NO_MEM = 1;
const size_t ERR_OK = 0;


template<class T>
void TArray<T>::QSort(int l, int r)
{
	if (array[(l + r) / 2].GetItemValue() == nullptr) {
		return;
	}
	double x = array[(l + r) / 2].GetItemValue()->Square();
	std::cout << "X is " << x << "\n";

	int i = l;
	int j = r;
	while (i <= j)
	{
		while (array[i].GetItemValue() != nullptr && array[i].GetItemValue()->Square() < x && i < Size()) i++;
		while (array[j].GetItemValue() != nullptr && array[j].GetItemValue()->Square() > x && j >= 0) j--;
		if (i <= j)
		{
			TArrayItem<T> tmp;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			i++;
			j--;
		}
	}
	if (i<r)
		QSort(i, r);

	if (l<j)
		QSort(l, j);
}



template<class T>
void TArray<T>::MQSort(int l, int r)
{
	if (array[(l + r) / 2].GetItemValue() == nullptr) {
		return;
	}
	double x = array[(l + r) / 2].GetItemValue()->Square();
	std::cout << "X is " << x << "\n";
	int i = l;
	int j = r;
	while (i <= j)
	{
		while (array[i].GetItemValue() != nullptr && array[i].GetItemValue()->Square() < x && i < Size()) i++;
		while (array[j].GetItemValue() != nullptr && array[j].GetItemValue()->Square() > x && j >= 0) j--;
		if (i <= j)
		{
			TArrayItem<T> tmp;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			i++;
			j--;
		}
	}
	if (i < r) {
		MQSort(i, r);
	}
	if (l < j) {
		auto left = std::async(std::launch::async, [&]() {
			return MQSort(l, j);
		});
		//MQSort(l, j);
	}

}



template<class T>
TArray<T>::TArray(size_t arrSize)
{
	size = arrSize;
	array = new TArrayItem<T>[arrSize + 1];
}

template<class T>
TArray<T>::TArray(size_t arrSize, const TArrayItem<T> * initObj)
{
	size = arrSize;
	array = new TArrayItem<T>[arrSize];
	for (size_t i = 0; i < size; i++) {
		//array[i] = *initObj;
		//*(&(*array) + i) = *initObj;
	}
}


template<class T>
int TArray<T>::Size()
{
	return size;
}


template<class T>
size_t TArray<T>::ElementInsert(TArrayItem<T> * obj, size_t index)
{
	if (index >= size) {
		std::cout << "Index too high" << std::endl;
	}
	//for (size_t i = index; i < size - 1; ++i) {
	//	array[i + 1] = array[i];
	//}
	else {
		*(&(*array) + index) = *obj;
		//array[index] = *obj;
	}
	return ERR_OK;
}


template<class T>
void TArray<T>::ElementDelete(size_t index)
{
	//array[index].SetPtr(nullptr);
	(*(&(*array) + index)).SetPtr(nullptr);
	/*for (size_t i = index; i < size; ++i) {
		array[i] = array[i + 1];
		--size;
		array = (TArrayItem *)realloc(array, size * sizeof(TArrayItem));
	}*/
}


template<class T>
TArrayItem<T>& TArray<T>::ElementGet(size_t index)
{
	return *(&(*array) + index);
//	return array[index];
}

template<class A>
std::ostream& operator<< (std::ostream& os, const TArray<A>& arr)
{
	for (size_t i = 0; i < arr.size; ++i) {
		os << "Element " << i << ": " << std::endl << *(&(*arr.array) + i) << std::endl;
	}
	return os;
}

template<class T>
TArray<T>::~TArray()
{
	//delete[] array;
	array = nullptr;
	std::cout << "Array deleted" << std::endl;
}

template <class T> TIterator<TArrayItem<T>, T> TArray<T>::begin()
{
	return TIterator<TArrayItem<T>, T>(array);
}

template <class T> TIterator<TArrayItem<T>, T> TArray<T>::end()
{
	//std::shared_ptr<TArrayItem<T>> a(&(this->ElementGet(size)));
	//return TIterator<TArrayItem<T>, T>(nullptr);
	return TIterator<TArrayItem<T>, T>(&array[size]);
}


#include "rectangle.h"
#include "rhombus.h"
#include "trapeze.h"
#include "TArrayItem.h"
#include "figure.h"

/*
template class TArray<Rectangle>;
template std::ostream& operator<<(std::ostream& os, const TArray<Rectangle>& obj);
template class TArray<Rhombus>;
template std::ostream& operator<<(std::ostream& os, const TArray<Rhombus>& obj);
template class TArray<Trapeze>;
template std::ostream& operator<<(std::ostream& os, const TArray<Trapeze>& obj);
*/
template class TArray<Figure>;
template std::ostream& operator<<(std::ostream& os, const TArray<Figure>& obj);
