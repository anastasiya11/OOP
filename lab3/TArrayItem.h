#pragma once
#include "rectangle.h"
#include "rhombus.h"
#include "trapeze.h"
#include <memory>
class TArrayItem
{
public:
	TArrayItem();
	TArrayItem(const std::shared_ptr<Figure>& figure);
	void SetPtr(const std::shared_ptr<Figure>& figure);
	friend std::ostream& operator<<(std::ostream& os, const TArrayItem& obj);
	double Square();
	~TArrayItem();
private:
	std::shared_ptr<Figure> figure;
};
