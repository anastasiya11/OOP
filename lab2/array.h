#pragma once
#include "rectangle.h"

class TArray
{
public:
	TArray() = default;
	TArray(size_t size);
	TArray(size_t size, const Rectangle *initObj);
	size_t ElementInsert(Rectangle *obj, size_t index);
	void ElementDelete(size_t index);
	Rectangle& ElementGet(size_t index);
	friend std::ostream& operator <<(std::ostream& os, const TArray& arr);
	~TArray();

private:
	Rectangle *array;
	size_t size;
};
