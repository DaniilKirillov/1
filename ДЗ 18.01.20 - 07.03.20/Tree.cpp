#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int data;
	Node* left = 0;
	Node* right = 0;
};

struct Tree {
	Node* root;

	bool dfs(Node* t, int x) {
		if (t->data == x) return 1;
		if (t->left != 0) {
			if (dfs(t->left, x) == 1) return 1;
		}
		if (t->right != 0) {
			if (dfs(t->right, x) == 1) return 1;
		}
		return 0;
	}

	bool bfs(Node* t, int x) {
		queue <Node*> A;
		A.push(root);
		while (!A.empty()) {
			Node* p = A.front();
			A.pop();
			if (p->data == x) return 1;
			if (p->left != 0) A.push(p->left);
			if (p->right != 0) A.push(p->right);
		}
		return 0;
	}
	// Поиск по дереву поиска:
	bool dfs1(Node* t, int x) {
		if (t->data == x) return 1;
		if (x < t->data && t->left != 0) {
			if (dfs1(t->left, x) == 1) return 1;
		}
		if (x > t->data&& t->right != 0) {
			if (dfs1(t->right, x) == 1) return 1;
		}
		return 0;
	}

	void del(Node* t) {
		if (t->left != 0) {
			del(t->left);
		}
		if (t->right != 0) {
			del(t->right);
		}
		delete t;
	}

	~Tree() {
		del(root);
	}
};