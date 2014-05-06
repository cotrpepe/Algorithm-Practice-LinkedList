#include "linked_list.h"

int main(void) {
	LinkedList list;
	list.add(1);
	list.add(2);
	list.add(3);
	list.add(5);
	list.print();

	cout << list.del(1) << endl;
	list.print();

	cout << list.del(3) << endl;
	list.print();

	cout << list.del(5) << endl;
	list.print();
}
