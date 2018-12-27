#include "array.h"

const size_t ERR_NO_MEM = 1;
const size_t ERR_OK = 0;


TArray::TArray(size_t arrSize)
{
	size = arrSize;
	array = new TArrayItem[arrSize];
	//array = (TArrayItem *)calloc(sizeof(TArrayItem), arrSize);
	//for (int i = 0; i < arrSize; ++i) {
	//	array[i] = ;
	//}
}

TArray::TArray(size_t arrSize, const TArrayItem * initObj)
{
	size = arrSize;
	array = new TArrayItem[arrSize];
	for (size_t i = 0; i < size; i++) {
		array[i] = *initObj;
	}
}

int TArray::Size()
{
	return size;
}

size_t TArray::ElementInsert(TArrayItem * obj, size_t index)
{
	if (index >= size) {
		std::cout << "Index too high" << std::endl;
	}
	//for (size_t i = index; i < size - 1; ++i) {
	//	array[i + 1] = array[i];
	//}
	else {
		array[index] = *obj;
	}
	return ERR_OK;
}

void TArray::ElementDelete(size_t index)
{
	std::shared_ptr<Rectangle> sp = nullptr;
	array[index].SetPtr(nullptr);

	/*for (size_t i = index; i < size; ++i) {
		array[i] = array[i + 1];
		--size;
		array = (TArrayItem *)realloc(array, size * sizeof(TArrayItem));
	}*/
}

TArrayItem &TArray::ElementGet(size_t index)
{
	return array[index];
}


std::ostream& operator<< (std::ostream& os, const TArray& arr)
{
	for (size_t i = 0; i < arr.size; ++i) {
		os << "Element " << i << ": " << std::endl << arr.array[i] << std::endl;
	}
	return os;
}

TArray::~TArray()
{
	delete[] array;
	array = nullptr;
	std::cout << "Array deleted" << std::endl;
}
