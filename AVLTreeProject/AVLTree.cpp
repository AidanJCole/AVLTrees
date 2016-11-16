#include "stdafx.h"
#include "AVLTree.h"
#include <vector>
#include <iostream>
using namespace std;
int count;
node* root;


AVLTree::AVLTree()
{
	count = 0;
	root = NULL;
}


AVLTree::~AVLTree()
{
}

bool AVLTree::insert(int key, int value) {
	if (root == NULL) {
		root = new node;
		root->key = key;
		root->value = value;
		count++;
		return true;
	}
	else {
		return recurInsert(root, key, value);
	}
}

bool AVLTree::recurInsert(node* base, int key, int value) {
	if (base == NULL || key == base->key) {
		return false;
	}
	bool temp = false;
	if (key <= base->key) {
		if (base->lessEq == NULL) {
			base->lessEq = new node;
			base->lessEq->key = key;
			base->lessEq->value = value;
			count++;
			return true;
		}
		temp = recurInsert(base->lessEq, key, value);
	}
	if (base->more == NULL) {
		base->more = new node;
		base->more->key = key;
		base->more->value = value;
		count++;
		return true;
	}
	return temp || recurInsert(base->more, key, value);
}

void AVLTree::print() {
	recurPrint(root, 0);
}

void AVLTree::recurPrint(node* base, int depth) {
	if (base == NULL) {
		return;
	}
	recurPrint(base->more, depth + 1);
	for (int i = 0; i < depth; i++) {
		cout << "\t";
	}
	cout << base->key << " " << base->value << endl;
	recurPrint(base->lessEq, depth + 1);
}

int AVLTree::getHeight() {
	return recurHeight(root);
}

int AVLTree::recurHeight(node* base) {
	if (base == NULL) {
		return 0;
	}
	int left = recurHeight(base->lessEq);
	int right = recurHeight(base->more);
	int ret = left > right ? left : right;
	return ret + 1;
}

int AVLTree::getSize() {
	return count;
}

bool AVLTree::find(int key, int& value) {
	return recurFind(root, key, value);
}

bool AVLTree::recurFind(node* base, int key, int& value) {
	if (base == NULL) {
		return false;
	}
	if (base->key == key) {
		value = base->value;
		return true;
	}
	if (base->key >= key) {
		return recurFind(base->lessEq, key, value);
	}
	return recurFind(base->more, key, value);
}

vector<int> AVLTree::findRange(int lowkey, int highkey) {
	vector<int> returner;
	vector<int>& ref = returner;
	recurRange(root, ref, lowkey, highkey);
	return returner;
}

void AVLTree::recurRange(node* base, vector<int>& ref, int lowkey, int highkey) {
	if (base == NULL) {
		return;
	}
	if (base->key >= lowkey && base->key <= highkey) {
		ref.insert(ref.end(), base->key);
		ref.insert(ref.end(), base->value);
		recurRange(base->more, ref, lowkey, highkey);
		recurRange(base->lessEq, ref, lowkey, highkey);
	}
	else if (base->key >= highkey) {
		recurRange(base->lessEq, ref, lowkey, highkey);
	}
	else if (base->key <= lowkey) {
		recurRange(base->more, ref, lowkey, highkey);
	}
}

void AVLTree::leftRotate(node* base) {
	if (base == NULL) {
		return;
	}
	if (base == root) {

	}
	else {

	}
}