#include "TArrayItem.h"


TArrayItem::TArrayItem() : figure(nullptr)
{
	std::cout << "TArrayItem created" << std::endl;
}

void TArrayItem::SetPtr(const std::shared_ptr<Figure>& my_figure)
{
	figure = my_figure;
}

double TArrayItem::Square()
{
	return figure->Square();
}


TArrayItem::TArrayItem(const std::shared_ptr<Figure>& figure) : figure(figure)
{
	std :: cout << "TArrayItem created" << std::endl;
}


TArrayItem::~TArrayItem()
{
	std::cout << "TArrayItem deleted" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const TArrayItem& obj)
{
	if (obj.figure) {
		obj.figure->Print();
	}
	return os;
}
