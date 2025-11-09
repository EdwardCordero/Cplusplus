#pragma once

template <typename T>
struct Node {
    Node() : value(T{}), next(nullptr) {};
    T value;
    Node<T>* next;
};