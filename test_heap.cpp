// test_heap.cpp
#include <gtest/gtest.h>
#include "heap.h"

class HeapTest : public ::testing::Test {
protected:
    Heap heap;
};

// Новая куча пуста
TEST_F(HeapTest, NewHeapIsEmpty) {
    EXPECT_TRUE(heap.empty());
    EXPECT_EQ(heap.size(), 0u);
}

// push увеличивает размер
TEST_F(HeapTest, PushIncreasesSize) {
    heap.push(5);
    EXPECT_EQ(heap.size(), 1u);
    heap.push(3);
    EXPECT_EQ(heap.size(), 2u);
}

// top возвращает корень без удаления
TEST_F(HeapTest, TopDoesNotRemove) {
    heap.push(42);
    EXPECT_EQ(heap.top(), 42);
    EXPECT_EQ(heap.size(), 1u);
}

// pop извлекает элементы в порядке приоритета (min-heap)
TEST_F(HeapTest, PopReturnsSortedOrder) {
    heap.push(5);
    heap.push(1);
    heap.push(3);
    heap.push(2);
    heap.push(4);

    EXPECT_EQ(heap.pop(), 1);
    EXPECT_EQ(heap.pop(), 2);
    EXPECT_EQ(heap.pop(), 3);
    EXPECT_EQ(heap.pop(), 4);
    EXPECT_EQ(heap.pop(), 5);
}

// Дубликаты обрабатываются корректно
TEST_F(HeapTest, HandlesDuplicates) {
    heap.push(7);
    heap.push(7);
    heap.push(7);
    EXPECT_EQ(heap.pop(), 7);
    EXPECT_EQ(heap.pop(), 7);
    EXPECT_EQ(heap.pop(), 7);
}

// pop из пустой кучи бросает исключение
TEST_F(HeapTest, PopOnEmptyThrows) {
    EXPECT_THROW(heap.pop(), std::out_of_range);
}

// top из пустой кучи бросает исключение
TEST_F(HeapTest, TopOnEmptyThrows) {
    EXPECT_THROW(heap.top(), std::out_of_range);
}

// После всех pop куча пуста
TEST_F(HeapTest, EmptyAfterAllPops) {
    heap.push(1);
    heap.push(2);
    heap.pop();
    heap.pop();
    EXPECT_TRUE(heap.empty());
}