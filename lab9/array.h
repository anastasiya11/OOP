#pragma once
#include "TArrayItem.h"
#include "TIterator.h"

template <class T>
class TArray
{
public:
	void QSort(int l, int r);
	void MQSort(int l, int r);
	TArray() = default;
	TArray(size_t size);
	TArray(size_t size, const TArrayItem<T> * initObj);
	size_t ElementInsert(TArrayItem<T> *obj, size_t index);
	void ElementDelete(size_t index);
	TArrayItem<T>& ElementGet(size_t index);
	int Size();
	void print();
	template <class A> friend std::ostream& operator <<(std::ostream& os, const TArray<A>& arr);
	TIterator<TArrayItem<T>, T> begin();
	TIterator<TArrayItem<T>, T> end();
	~TArray();

private:
	TArrayItem<T> * array;
	size_t size;
	
};
