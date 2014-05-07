#include "linked_list.h"
#include <string>

int main(void) {
	LinkedList<int> list;

	list.add(1);
	list.add(2);
	list.add(3);
	list.add(4);
	list.print();

	cout << list.del(1) << endl;
	list.print();

	cout << list.del(9) << endl;
	list.print();

	cout << list.del(3) << endl;
	list.print();

	cout << list.del(4) << endl;
	list.print();

	LinkedList<string> list2;

	list2.add("aaa");
	list2.add("abb");
	list2.add("bbb");
	list2.add("ccc");
	list2.print();

	cout << list2.del("aaa") << endl;
	list2.print();

	cout << list2.del("xxx") << endl;
	list2.print();

	cout << list2.del("bbb") << endl;
	list2.print();

	cout << list2.del("ccc") << endl;
	list2.print();
}
