// test_queue.cpp
#include <gtest/gtest.h>
#include "queue.h"

class QueueTest : public ::testing::Test {
protected:
    Queue queue;
};

// Проверка: новая очередь пуста
TEST_F(QueueTest, NewQueueIsEmpty) {
    EXPECT_TRUE(queue.empty());
    EXPECT_EQ(queue.size(), 0u);
}

// Проверка: push увеличивает размер
TEST_F(QueueTest, PushIncreasesSize) {
    queue.push(1);
    EXPECT_EQ(queue.size(), 1u);
    EXPECT_FALSE(queue.empty());

    queue.push(2);
    EXPECT_EQ(queue.size(), 2u);
}

// Проверка: pop возвращает элементы в порядке FIFO
TEST_F(QueueTest, PopReturnsFifoOrder) {
    queue.push(10);
    queue.push(20);
    queue.push(30);

    EXPECT_EQ(queue.pop(), 10);
    EXPECT_EQ(queue.pop(), 20);
    EXPECT_EQ(queue.pop(), 30);
}

// Проверка: pop уменьшает размер
TEST_F(QueueTest, PopDecreasesSize) {
    queue.push(1);
    queue.push(2);
    queue.pop();
    EXPECT_EQ(queue.size(), 1u);
}

// Проверка: pop из пустой очереди бросает исключение
TEST_F(QueueTest, PopOnEmptyThrows) {
    EXPECT_THROW(queue.pop(), std::out_of_range);
}

// Проверка: после опустошения очередь снова пуста
TEST_F(QueueTest, EmptyAfterAllPops) {
    queue.push(1);
    queue.pop();
    EXPECT_TRUE(queue.empty());
}

// Граничные значения
TEST_F(QueueTest, NegativeAndZeroValues) {
    queue.push(0);
    queue.push(-5);
    EXPECT_EQ(queue.pop(), 0);
    EXPECT_EQ(queue.pop(), -5);
}