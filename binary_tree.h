// binary_tree.h
#pragma once

class BinaryTree {
public:
    BinaryTree() = default;
    ~BinaryTree() = default;

    void push(int value);           // вставка
    bool pop(int value);            // удаление по значению
    bool search(int value) const;   // поиск
    bool empty() const;
    size_t size() const;
};