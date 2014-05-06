#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <iostream>

using namespace std;

class LinkedList {
public:
	LinkedList(void);
	~LinkedList(void);
	void print(void);
	void add(int value);
	bool del(int value);

private:
	struct Node {
		int value;
		Node *next;
	};

	Node *head;
	Node *last;
};

#endif // __LINKED_LIST_H__

