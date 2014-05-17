#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <memory>

template <typename T>
class LinkedList {
public:
	LinkedList(void) : m_head(nullptr), m_last(nullptr), m_size(0) {}
	virtual ~LinkedList(void); 
	
	void add(const T& value); 
	bool del(const T& value);
	bool empty(void) const;
	int size(void) const;

private:
	struct Node {
		T value;
		std::shared_ptr<Node> next;
	};
	
	std::shared_ptr<Node> m_head;
	std::shared_ptr<Node> m_last;
	int m_size;
};

template <typename T>
LinkedList<T>::~LinkedList(void) = default;

template <typename T>
void LinkedList<T>::add(const T& value) {
	std::shared_ptr<Node> n(new Node);
	n->value = value;
	n->next = nullptr;
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
bool LinkedList<T>::del(const T& value) {
	bool found = false;
	std::shared_ptr<Node> current = m_head;
	std::shared_ptr<Node> prev = nullptr;
	while (current != nullptr) {
		if (current->value == value) {
			found = true;
			m_size--;
			if (prev == nullptr) {
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
	return m_head == nullptr;
}

template <typename T>
int LinkedList<T>::size(void) const {
	return m_size;
}

#endif // __LINKED_LIST_H__

