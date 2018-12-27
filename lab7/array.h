#pragma once
#include "TArrayItem.h"
#include "TIterator.h"
#include "binary_tree.h"
#include "IRemoveCriteriaAll.h"
#include "IRemoveCriteriaByValue.h"

template <class T, class TT>
class TArray
{
public:
	void TArray<T, TT>::RemoveSubitem(int size);
	void TArray<T, TT>::InsertSubitem(TT* value);
	int GetNextFree();
	TArray() = default;
	TArray(size_t size);
	TArray(size_t size, const TArrayItem<T> * initObj);
	size_t ElementInsert(TArrayItem<T> *obj, size_t index);
	void ElementDelete(size_t index);
	TArrayItem<T>& ElementGet(size_t index);
	int Size();
	template <class A, class B> friend std::ostream& operator <<(std::ostream& os, const TArray<A, B>& arr);
	TIterator<TArrayItem<T>, T> begin();
	TIterator<TArrayItem<T>, T> end();
	~TArray();

private:
	TArrayItem<T> * array;
	bool * freearr;
	size_t size;
};
