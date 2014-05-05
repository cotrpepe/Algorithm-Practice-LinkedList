#include <iostream>

using namespace std;

struct Node {
	int value;
	Node *next;
};

class LinkedList {
public:
	LinkedList(void);
	~LinkedList(void);
	void print(void);
	void add(int value);
private:
	Node *head;
	Node *last;
};

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

int main(void) {
	LinkedList list;
	list.add(1);
	list.add(2);
	list.print();
}