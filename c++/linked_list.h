#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

template <typename T>
class LinkedList {
public:
	LinkedList(void) : head(NULL), last(NULL), m_size(0) {}
	~LinkedList(void); 
	void add(const T value); 
	bool del(const T value);
	bool empty(void) const;
	int size(void) const;

private:
	struct Node {
		T value;
		Node *next;
	};

	Node *head;
	Node *last;
	int m_size;
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
	m_size++;
}

template <typename T>
bool LinkedList<T>::del(const T value) {
	bool found = false;
	Node *current = head;
	Node *prev = NULL;
	while (current != NULL) {
		if (current->value == value) {
			found = true;
			m_size--;
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

template <typename T>
int LinkedList<T>::size(void) const {
	return m_size;
}

#endif // __LINKED_LIST_H__

