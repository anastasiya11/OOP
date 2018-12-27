#pragma once
#include "TArrayItem.h"

template <class T>
class TArray
{
public:
	TArray() = default;
	TArray(size_t size);
	TArray(size_t size, const TArrayItem<T> * initObj);
	size_t ElementInsert(TArrayItem<T> *obj, size_t index);
	void ElementDelete(size_t index);
	TArrayItem<T>& ElementGet(size_t index);
	int Size();
	template <class A> friend std::ostream& operator <<(std::ostream& os, const TArray<A>& arr);
	~TArray();

private:
	std::shared_ptr<TArrayItem<T>> array;
	size_t size;
};
