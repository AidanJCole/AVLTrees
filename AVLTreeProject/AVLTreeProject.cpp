// AVLTreeProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "AVLTree.h"
#include <iostream>

using namespace std;
int main()
{
	AVLTree tree;
	tree.insert(40, 12);
	tree.insert(20, 16);
	tree.insert(50, 11);
	tree.insert(10, 54);
	tree.insert(30, 16);
	tree.insert(45, 72);
	tree.print();
	cout << tree.getHeight() << endl;
	cout << tree.getSize() << endl;
	int var;
	int& value = var;
	cout << tree.find(20, value) << endl;
	cout << var << endl;
	cout << tree.find(234, value) << endl;
	vector<int> temp = tree.findRange(10,30);
	for (int i = 0; i < temp.size(); i += 2) {
		cout << temp[i] << ", " << temp[i + 1] << endl;
	}
	int i = 0;
    return 0;
}

