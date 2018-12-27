#pragma once
#include "rectangle.h"
#include "rhombus.h"
#include "trapeze.h"
#include <memory>

template <class T>
class TArrayItem
{
public:
	TArrayItem();
	TArrayItem(const std::shared_ptr<T>& figure);
	void SetPtr(const std::shared_ptr<T>& figure);
	template <class A> friend std::ostream& operator<<(std::ostream& os, const TArrayItem<A> & obj);
	template <class A> friend std::istream& operator >> (std::istream& is, const TArrayItem<A>& obj);
	double Square();
	~TArrayItem();
private:
	std::shared_ptr<T> figure;
};
