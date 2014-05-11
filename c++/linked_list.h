#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <iostream>

using namespace std;

template <typename T> class LinkedList {
public:
	LinkedList(void) : head(NULL), last(NULL) {}

	~LinkedList(void) {
		for (Node *n = head; n != NULL;) {
			Node *remove_node = n;
			n = n->next;
			delete remove_node;
		}
	}

	string str(void) {
		string ret = "";
		for (Node *n = head; n != NULL; n = n->next) {
			ret += n->value;
			if (n->next != NULL) ret += " ";
		}
		return ret;
	}

	void add(const T value) {
		Node *n = new Node;
		n->value = value;
		n->next = NULL;
		if (head == NULL) {
			head = n;
			last = n;
		} else {
			last->next = n;
			last = n;
		}	
	}

	bool del(const T value) {
		bool found = false;
		Node *current = head;
		Node *prev = NULL;
		while (current != NULL) {
			if (current->value == value) {
				found = true;
				if (prev == NULL) {
					head = current->next;
				} else {
					prev->next = current->next;
				}
			}
			prev = current;
			current = current->next;
		}
		return found;
	}

private:
	struct Node {
		T value;
		Node *next;
	};

	Node *head;
	Node *last;
};

#endif // __LINKED_LIST_H__

