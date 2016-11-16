#pragma once
#include <vector>
struct node
	{
		int key;
		int value;
		node* lessEq = NULL;
		node* more = NULL;
	};
class AVLTree
{
public:
	AVLTree();
	~AVLTree();
	bool AVLTree::insert(int key, int value);
	int AVLTree::getHeight();
	int AVLTree::getSize();
	void AVLTree::print();
	bool AVLTree::find(int key, int&value);
	std::vector<int> AVLTree::findRange(int lowkey, int highkey);

private:
	int count;
	node* root;
	bool AVLTree::recurInsert(node* base, int key, int value);
	void AVLTree::recurPrint(node* base, int depth);
	int AVLTree::recurHeight(node* base);
	bool AVLTree::recurFind(node* base, int key, int& value);
	void AVLTree::recurRange(node* base, std::vector<int>& ref, int lowkey, int highkey);
	void AVLTree::leftRotate(node* base);
};

