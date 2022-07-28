#include "gtest/gtest.h"
#include "../../include/datastructures/List/LinkedList.hpp"

TEST(push_front, empty) {
    std::unique_ptr<DataStructures::List<int>> l = std::make_unique<DataStructures::LinkedList<int>>();
    l->push_front(1);
    EXPECT_EQ(l->front(), 1);
    EXPECT_EQ(l->at(0), 1);
    EXPECT_EQ(l->size(), 1);
}

TEST(push_front, not_empty) {
    std::unique_ptr<DataStructures::List<int>> l = std::make_unique<DataStructures::LinkedList<int>>();
    l->push_front(1);
    l->push_front(2);
    l->push_front(3);
    EXPECT_EQ(l->front(), 3);
    EXPECT_EQ(l->back(), 1);
    EXPECT_EQ(l->at(0), 3);
    EXPECT_EQ(l->at(1), 2);
    EXPECT_EQ(l->at(2), 1);
    EXPECT_EQ(l->size(), 3);
}

TEST(insert, empty) {
    std::unique_ptr<DataStructures::List<int>> l = std::make_unique<DataStructures::LinkedList<int>>();
    l->insert(3, 0);
    EXPECT_EQ(l->at(0), 3);
    EXPECT_EQ(l->size(), 1);
}

TEST(insert, not_empty_front) {
    std::unique_ptr<DataStructures::List<int>> l = std::make_unique<DataStructures::LinkedList<int>>();
    l->push_front(1);
    l->push_front(2);
    l->push_front(3);
    l->push_front(4);
    l->insert(10, 0);
    EXPECT_EQ(l->front(), 10);
    EXPECT_EQ(l->at(0), 10);
    EXPECT_EQ(l->at(1), 4);
    EXPECT_EQ(l->at(2), 3);
    EXPECT_EQ(l->at(3), 2);
    EXPECT_EQ(l->at(4), 1);
    EXPECT_EQ(l->back(), 1);
    EXPECT_EQ(l->size(), 5);
}

TEST(insert, not_empty_middle) {
    std::unique_ptr<DataStructures::List<int>> l = std::make_unique<DataStructures::LinkedList<int>>();
    l->push_front(1);
    l->push_front(2);
    l->push_front(3);
    l->push_front(4);
    l->insert(10, 3);
    EXPECT_EQ(l->front(), 4);
    EXPECT_EQ(l->at(0), 4);
    EXPECT_EQ(l->at(1), 3);
    EXPECT_EQ(l->at(2), 2);
    EXPECT_EQ(l->at(3), 10);
    EXPECT_EQ(l->at(4), 1);
    EXPECT_EQ(l->back(), 1);
    EXPECT_EQ(l->size(), 5);
}

TEST (insert, not_empty_out_of_bounds_greater) {
    std::unique_ptr<DataStructures::List<int>> l = std::make_unique<DataStructures::LinkedList<int>>();
    l->push_front(1);
    l->push_front(2);
    l->push_front(3);
    l->push_front(4);
    EXPECT_THROW({
        try {
            // fail if this works
            l->insert(10, 4);
            FAIL();
        } catch(std::out_of_range &e) {
            EXPECT_STREQ("Index out of bounds.", e.what());
            throw;
        }
    }, std::out_of_range);
}

TEST (insert, not_empty_out_of_bounds_less) {
    std::unique_ptr<DataStructures::List<int>> l = std::make_unique<DataStructures::LinkedList<int>>();
    l->push_front(1);
    l->push_front(2);
    l->push_front(3);
    l->push_front(4);
    EXPECT_THROW({
        try {
            // fail if this works
            l->insert(10, -1);
            FAIL();
        } catch(std::out_of_range &e) {
            EXPECT_STREQ("Index out of bounds.", e.what());
            throw;
        }
    }, std::out_of_range);
}

TEST (push_back, empty) {

}

TEST (push_back, not_empty) {

}

TEST (remove, empty) {

}

TEST (remove, not_empty_front) {

}

TEST (remove, not_empty_back) {

}

TEST (remove, not_empty_middle) {

}

TEST (remove, not_empty_out_of_bounds) {

}

TEST (pop_front, empty) {

}

TEST (pop_front, not_empty) {

}

TEST (pop_back, empty) {

}

TEST (pop_back, not_empty) {

}

TEST (at, empty) {

}

TEST (at, not_empty_front) {

}

TEST (at, not_empty_back) {

}

TEST (at, not_empty_middle) {

}

TEST (at, not_empty_out_of_bounds_greater) {

}

TEST (at, not_empty_out_of_bounds_less) {

}

TEST (front, empty) {

}

TEST (front, not_empty) {

}

TEST (back, empty) {

}

TEST (back, not_empty) {

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}