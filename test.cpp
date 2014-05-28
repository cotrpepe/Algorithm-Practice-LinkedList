#include <gtest/gtest.h>
#include <string>
#include <memory>
#include "linked_list.h"

TEST(LinkedList, empty_int) {
	std::unique_ptr<LinkedList<int>> list(new LinkedList<int>());
	ASSERT_TRUE(list->empty());

	list->add(1);
	ASSERT_FALSE(list->empty());
}

TEST(LinkedList, empty_string) {
	std::unique_ptr<LinkedList<std::string>> list(new LinkedList<std::string>());
	ASSERT_TRUE(list->empty());

	list->add("test");
	ASSERT_FALSE(list->empty());
}

TEST(LinkedList, size_int) {
	std::unique_ptr<LinkedList<int>> list(new LinkedList<int>());
	ASSERT_EQ(0, list->size());

	list->add(1);
	ASSERT_EQ(1, list->size());

	list->add(2);
	ASSERT_EQ(2, list->size());

	list->del(1);
	ASSERT_EQ(1, list->size());

	list->del(2);
	ASSERT_EQ(0, list->size());
}

TEST(LinkedList, size_string) {
	std::unique_ptr<LinkedList<std::string>> list(new LinkedList<std::string>());
	ASSERT_EQ(0, list->size());

	list->add("aaa");
	ASSERT_EQ(1, list->size());

	list->add("bbb");
	ASSERT_EQ(2, list->size());

	list->del("aaa");
	ASSERT_EQ(1, list->size());

	list->del("bbb");
	ASSERT_EQ(0, list->size());
}

TEST(LinkedList, add_del_int) {
	std::unique_ptr<LinkedList<int>> list(new LinkedList<int>());
	ASSERT_THROW(list->del(1), std::runtime_error);

	list->add(1);
	list->add(2);
	ASSERT_THROW(list->del(3), std::runtime_error);

	list->del(1);
	ASSERT_EQ(1, list->size());

	list->del(2);
	ASSERT_EQ(0, list->size());

	ASSERT_THROW(list->del(1), std::runtime_error);
	ASSERT_THROW(list->del(2), std::runtime_error);
}

TEST(LinkedList, add_del_string) {
	std::unique_ptr<LinkedList<std::string>> list(new LinkedList<std::string>());
	ASSERT_THROW(list->del("aaa"), std::runtime_error);

	list->add("aaa");
	list->add("bbb");
	ASSERT_THROW(list->del("ccc"), std::runtime_error);

	list->del("aaa");
	ASSERT_EQ(1, list->size());

	list->del("bbb");
	ASSERT_EQ(0, list->size());

	ASSERT_THROW(list->del("aaa"), std::runtime_error);
	ASSERT_THROW(list->del("bbb"), std::runtime_error);
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

