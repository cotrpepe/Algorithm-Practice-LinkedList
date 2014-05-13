#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

template <typename T>
class LinkedList {
public:
	LinkedList(void) : head(NULL), last(NULL) {}
	~LinkedList(void); 
	void add(const T value); 
	bool del(const T value);
	bool empty(void) const;

private:
	struct Node {
		T value;
		Node *next;
	};

	Node *head;
	Node *last;
};

template <typename T>
LinkedList<T>::~LinkedList(void) {
	for (Node *n = head; n != NULL;) {
		Node *remove_node = n;
		n = n->next;
		delete remove_node;
	}
}

template <typename T>
void LinkedList<T>::add(const T value) {
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

template <typename T>
bool LinkedList<T>::del(const T value) {
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

template <typename T>
bool LinkedList<T>::empty(void) const {
	return head == NULL;
}

#endif // __LINKED_LIST_H__

