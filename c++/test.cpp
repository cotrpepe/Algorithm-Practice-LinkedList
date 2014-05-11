#include <gtest/gtest.h>
#include <string>
#include "linked_list.h"

TEST(LinkedList, str) {
	LinkedList<int> list;
	list.add(1);
	list.add(2);
	list.add(3);

	//ASSERT_EQ("1 2 3", list.str());
}

TEST(LinkedList, add_and_del) {
        LinkedList<int> list;
        list.add(1);
	list.add(2);
	list.add(3);

	ASSERT_FALSE(list.del(0));
	ASSERT_TRUE(list.del(1));
	ASSERT_TRUE(list.del(3));
	ASSERT_TRUE(list.del(2));
	ASSERT_FALSE(list.del(2));
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

