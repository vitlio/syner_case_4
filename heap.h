#pragma once

class Heap {
public:
    Heap() = default;
    ~Heap() = default;

    void push(int value);
    int pop();
    int top() const;
    bool empty() const;
    size_t size() const;
};