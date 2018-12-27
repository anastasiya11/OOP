#pragma once
#include "array.h"


class TBinaryTree
{
public:
	TBinaryTree();
	void push(void *value);
	int Size();
	~TBinaryTree();
//private:
	TBinaryTree *left;
	TBinaryTree *right;
	//T data;
	void *data;
	int size;
};
