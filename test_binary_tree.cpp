// test_binary_tree.cpp
#include <gtest/gtest.h>
#include "binary_tree.h"

class BinaryTreeTest : public ::testing::Test {
protected:
    BinaryTree tree;
};

// Новое дерево пусто
TEST_F(BinaryTreeTest, NewTreeIsEmpty) {
    EXPECT_TRUE(tree.empty());
    EXPECT_EQ(tree.size(), 0u);
}

// push увеличивает размер
TEST_F(BinaryTreeTest, PushIncreasesSize) {
    tree.push(10);
    EXPECT_EQ(tree.size(), 1u);
    tree.push(5);
    EXPECT_EQ(tree.size(), 2u);
}

// search находит добавленные элементы
TEST_F(BinaryTreeTest, SearchFindsExisting) {
    tree.push(10);
    tree.push(5);
    tree.push(15);

    EXPECT_TRUE(tree.search(10));
    EXPECT_TRUE(tree.search(5));
    EXPECT_TRUE(tree.search(15));
}

// search не находит отсутствующие элементы
TEST_F(BinaryTreeTest, SearchReturnsFalseForMissing) {
    tree.push(10);
    tree.push(5);

    EXPECT_FALSE(tree.search(99));
    EXPECT_FALSE(tree.search(-1));
}

// search на пустом дереве
TEST_F(BinaryTreeTest, SearchOnEmptyTree) {
    EXPECT_FALSE(tree.search(1));
}

// pop удаляет элемент и уменьшает размер
TEST_F(BinaryTreeTest, PopRemovesElement) {
    tree.push(10);
    tree.push(5);
    tree.push(15);

    EXPECT_TRUE(tree.pop(5));
    EXPECT_FALSE(tree.search(5));
    EXPECT_EQ(tree.size(), 2u);
}

// pop отсутствующего элемента возвращает false
TEST_F(BinaryTreeTest, PopMissingReturnsFalse) {
    tree.push(10);
    EXPECT_FALSE(tree.pop(99));
    EXPECT_EQ(tree.size(), 1u);
}

// pop корня работает корректно
TEST_F(BinaryTreeTest, PopRoot) {
    tree.push(10);
    tree.push(5);
    tree.push(15);

    EXPECT_TRUE(tree.pop(10));
    EXPECT_FALSE(tree.search(10));
    // остальные элементы на месте
    EXPECT_TRUE(tree.search(5));
    EXPECT_TRUE(tree.search(15));
}

// Дубликаты (или уникальность) — зависит от реализации
TEST_F(BinaryTreeTest, DuplicateHandling) {
    tree.push(10);
    tree.push(10);
    // Ожидаем, что дерево не хранит дубликаты
    EXPECT_EQ(tree.size(), 1u);
}

// После удаления всех элементов дерево пусто
TEST_F(BinaryTreeTest, EmptyAfterAllPops) {
    tree.push(1);
    tree.push(2);
    tree.pop(1);
    tree.pop(2);
    EXPECT_TRUE(tree.empty());
}