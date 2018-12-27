#pragma once
#include "rectangle.h"
#include "rhombus.h"
#include "trapeze.h"
#include "TAllocationBlock.h"
#include <memory>

template <class T>
class TArrayItem
{
public:
	TArrayItem();
	TArrayItem(const std::shared_ptr<T>& figure);
	void SetPtr(const std::shared_ptr<T>& figure);
	void SetPtr1(T* figure);
	std::shared_ptr<T> GetItemValue() const;
	T* GetItemValue1() const;
	TArrayItem<T> * GetNext();
	void SetNext(std::shared_ptr<TArrayItem<T>> &);
	template <class A> friend std::ostream& operator<<(std::ostream& os, const TArrayItem<A> & obj);
	template <class A> friend std::istream& operator >> (std::istream& is, const TArrayItem<A>& obj);
	void * operator new (size_t size);
	void operator delete(void *p);
	double Square();
	~TArrayItem();
private:
	std::shared_ptr<T> figure;
	static TAllocationBlock arrayitem_allocator;
	//std::shared_ptr<TArrayItem<T>> next;
};
