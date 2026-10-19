#pragma once

class Queue {
public:
    Queue() = default;
    ~Queue() = default;

    void push(int value);
    int pop();
    bool empty() const;
    size_t size() const;
};