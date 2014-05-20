#include <gtest/gtest.h>
#include <string>
#include "linked_list.h"

TEST(LinkedList, empty_int) {
	LinkedList<int> list;
	ASSERT_TRUE(list.empty());
	list.add(1);
	ASSERT_FALSE(list.empty());
}

TEST(LinkedList, empty_string) {
	LinkedList<std::string> list;
	ASSERT_TRUE(list.empty());
	list.add("test");
	ASSERT_FALSE(list.empty());
}

TEST(LinkedList, size_int) {
	LinkedList<int> list;
	ASSERT_EQ(0, list.size());

	list.add(1);
	ASSERT_EQ(1, list.size());

	list.add(2);
	ASSERT_EQ(2, list.size());

	list.del(1);
	ASSERT_EQ(1, list.size());

	list.del(2);
	ASSERT_EQ(0, list.size());
}

TEST(LinkedList, size_string) {
	LinkedList<std::string> list;
	ASSERT_EQ(0, list.size());

	list.add("aaa");
	ASSERT_EQ(1, list.size());

	list.add("bbb");
	ASSERT_EQ(2, list.size());

	list.del("aaa");
	ASSERT_EQ(1, list.size());

	list.del("bbb");
	ASSERT_EQ(0, list.size());
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

