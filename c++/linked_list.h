#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

template <typename T>
class LinkedList {
public:
	LinkedList(void) : m_head(NULL), m_last(NULL), m_size(0) {}
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

	Node *m_head;
	Node *m_last;
	int m_size;
};

template <typename T>
LinkedList<T>::~LinkedList(void) {
	for (Node *n = m_head; n != NULL;) {
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
	if (this->empty()) {
		m_head = n;
		m_last = n;
	} else {
		m_last->next = n;
		m_last = n;
	}
	m_size++;
}

template <typename T>
bool LinkedList<T>::del(const T value) {
	bool found = false;
	Node *current = m_head;
	Node *prev = NULL;
	while (current != NULL) {
		if (current->value == value) {
			found = true;
			m_size--;
			if (prev == NULL) {
				m_head = current->next;
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
	return m_head == NULL;
}

template <typename T>
int LinkedList<T>::size(void) const {
	return m_size;
}

#endif // __LINKED_LIST_H__

