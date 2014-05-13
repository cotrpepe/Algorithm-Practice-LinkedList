#include <gtest/gtest.h>
#include <string>
#include "linked_list.h"

TEST(LinkedList, empty_int) {
	LinkedList<int> list;
	ASSERT_TRUE(list.empty());
	list.add(1);
	ASSERT_FALSE(list.empty());
}

TEST(LinkedList, empty_double) {
	LinkedList<double> list;
	ASSERT_TRUE(list.empty());
	list.add(1.234);
	ASSERT_FALSE(list.empty());
}

TEST(LinkedList, empty_string) {
	LinkedList<std::string> list;
	ASSERT_TRUE(list.empty());
	list.add("test");
	ASSERT_FALSE(list.empty());
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

