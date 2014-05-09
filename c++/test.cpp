#include <gtest/gtest.h>
#include <string>
#include "linked_list.h"

TEST(LinkedList, print) {
        LinkedList<int> list;
        list.add(1);
        list.add(2);
        list.add(3);
        list.add(4);
        //ASSERT_EQ("1 2 3 4", list.print());
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

