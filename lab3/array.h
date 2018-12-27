#pragma once
#include "TArrayItem.h"

class TArray
{
public:
	TArray() = default;
	TArray(size_t size);
	TArray(size_t size, const TArrayItem * initObj);
	size_t ElementInsert(TArrayItem *obj, size_t index);
	void ElementDelete(size_t index);
	TArrayItem& ElementGet(size_t index);
	int Size();
	friend std::ostream& operator <<(std::ostream& os, const TArray& arr);
	~TArray();

private:
	TArrayItem * array;
	size_t size;
};
