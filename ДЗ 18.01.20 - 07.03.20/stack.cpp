#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next = 0;
};

struct stack {
	Node* head;
	stack(int a) {
		head = new Node;
		head->data = a;
	}
	void push(int a) {
		Node* temp = new Node;
		temp->data = a;
		temp->next = head;
		head = temp;
	}
	int pop() {
		Node* temp = head;
		head = head->next;
		int a = temp->data;
		delete temp;
		return a;
	}
	~stack() {
		while (head != 0) {
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}
};