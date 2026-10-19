// heap.h
#pragma once

class Heap {
public:
    Heap() = default;
    ~Heap() = default;

    void push(int value);
    int pop();          // извлекает корень (min или max)
    int top() const;    // просмотр корня
    bool empty() const;
    size_t size() const;
};