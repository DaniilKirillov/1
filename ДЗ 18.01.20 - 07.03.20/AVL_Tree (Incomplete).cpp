#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct Node{
	int data;
	Node* left = 0;
	Node* right = 0;
	int height(Node* a) {
		Node* temp = a;
		int hleft = 0;
		int hright = 0;
		if (a == 0) return 0;
		if (a->right) hright = height(a->right);
		if (a->left) hleft = height(a->left);
		return max(h1, h2) + 1;
	}
	int balance(Node* a) {
		return (height(a->left) - height(a->right));
	}
};

struct AVL_Tree {
	Node root;
	Node* smallturnleft(Node* a) {
		Node* b = a->right;
		a->right = b->left;
		b->left = a;
	}
	Node* smallturnright(Node* a) {
		Node* b = a->left;
		a->left = b->right;
		b->right = a;
	}
	Node* bigturnleft(Node* a) {
		smallturnright(a->right);
		smallturnleft(a);
	}
	Node* bigturnright(Node* a) {
		smallturnleft(a->left);
		smallturnright(a);
	}
};