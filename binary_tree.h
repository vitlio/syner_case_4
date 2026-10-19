
#pragma once

class BinaryTree {
public:
    BinaryTree() = default;
    ~BinaryTree() = default;

    void push(int value);
    bool pop(int value);
    bool search(int value) const;
    bool empty() const;
    size_t size() const;
};