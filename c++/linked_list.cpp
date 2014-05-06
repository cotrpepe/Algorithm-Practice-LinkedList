#include "linked_list.h"

LinkedList::LinkedList(void) : head(NULL), last(NULL) {}

LinkedList::~LinkedList(void) {
	for (Node *n = head; n != NULL;) {
		Node *remove_node = n;
		n = n->next;
		delete remove_node;
	}
}

void LinkedList::print(void) {
	for (Node *n = head; n != NULL; n = n->next) {
		cout << n->value;
		if (n->next != NULL) cout << " ";
	}
	cout << endl;
}

void LinkedList::add(int value) {
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

bool LinkedList::del(int value) {
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

