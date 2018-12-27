#include "stdafx.h"
#include "array.h"

const size_t ERR_NO_MEM = 1;
const size_t ERR_OK = 0;


TArray::TArray(size_t arrSize)
{
	size = arrSize;
	array = (Rectangle *)calloc(sizeof(Rectangle), arrSize);
}

TArray::TArray(size_t arrSize, const Rectangle *initObj)
{
	size = arrSize;
	array = (Rectangle *)calloc(sizeof(Rectangle), arrSize);
	for (size_t i = 0; i < size; i++) {
		array[i] = *initObj;
	}
}

size_t TArray::ElementInsert(Rectangle *obj, size_t index)
{
	if (!realloc(array, sizeof(Rectangle) * ++size)) {
		return ERR_NO_MEM;
	}
	for (size_t i = index; i < size - 1; ++i) {
		array[i + 1] = array[i];
	}
	array[index] = *obj;
	return ERR_OK;
}

void TArray::ElementDelete(size_t index)
{
	for (size_t i = index; i < size; ++i) {
		array[i] = array[i + 1];
		--size;
		array = (Rectangle *)realloc(array, size * sizeof(Rectangle));
	}
}

Rectangle &TArray::ElementGet(size_t index)
{
	return array[index];
}


std::ostream& operator<< (std::ostream& os, const TArray& arr)
{
	for (size_t i = 0; i < arr.size; ++i) {
		std::cout << arr.array[i];
	}
	return os;
}

TArray::~TArray()
{
	free(array);
	array = nullptr;
}
