#include "binary_tree.h"

using namespace std;


void TBinaryTree::push(void *value)
{
	data = value;
}



int TBinaryTree::Size()
{
	return size;
}


TBinaryTree::TBinaryTree()
{
	left = nullptr;
	right = nullptr;
	size = 0;
}





TBinaryTree::~TBinaryTree()
{
}


#include "array.h"
#include "figure.h"
