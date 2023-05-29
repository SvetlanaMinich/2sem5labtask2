#pragma once
#ifndef DEQUE_DEQUEITERATOR_H
#define DEQUE_DEQUEITERATOR_H
#include "Node.h"

template<class T>
class DequeIterator {
private:
    Node<T>* node;
    int index;
public:
    DequeIterator<T>(){}
    DequeIterator<T>(Node<T>* _node):node(_node){}
    DequeIterator<T>(Node<T>* _node, int _index):node(_node),index(_index){}
    T& operator*() const;
    T* operator->() const;
    DequeIterator<T>& operator++();
    DequeIterator<T> operator++(int n);
    DequeIterator<T>& operator--();
    DequeIterator<T> operator--(int n);
    DequeIterator<T> operator-(int n) const;
    DequeIterator<T> operator+(int n) const;
    int operator-(const DequeIterator<T>& _other) const;
    bool operator==(const DequeIterator<T>& _other) const;
    bool operator!=(const DequeIterator<T>& _other) const;
    bool operator<(const DequeIterator<T>& _other) const;
    bool operator>(const DequeIterator<T>& _other) const;
    DequeIterator<T>& operator+=(int n);
    DequeIterator<T>& operator-=(int n);
};


#endif //DEQUE_DEQUEITERATOR_H
