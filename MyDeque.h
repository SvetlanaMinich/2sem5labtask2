#pragma once
#include <iostream>
#ifndef DEQUE_MYDEQUE_H
#define DEQUE_MYDEQUE_H
#include "DequeIterator.cpp"

template<class T>
class MyDeque: public DequeIterator<T>
{
private:
    Node<T>* front;
    Node<T>* back;
    size_t capacity;
    size_t size;
    size_t frontInd;
    T* _data;
    void resize(size_t _capacity)
    {
        T* new_data = new T[_capacity];
        size_t _frontInd = (_capacity-size)/2;
        for(size_t i=0;i<size;i++)
        {
            new_data[_frontInd+i]=_data[frontInd+i];
        }
        delete[] _data;
        _data = new_data;
        capacity=_capacity;
        frontInd=_frontInd;
    }
public:
    MyDeque():front(nullptr),back(nullptr),capacity(0),size(0),frontInd(0),_data(nullptr){}
    DequeIterator<T> begin() const;
    DequeIterator<T> end() const;
    T& _front();
    T& _back();
    void push_front(const T& value);
    void push_back(const T& value);
    void pop_front();
    void pop_back();
    [[nodiscard]] bool empty() const;
    [[nodiscard]] size_t _size() const;
    //T& operator[](int _index);
    [[noreturn]] void clear();
};


#endif //DEQUE_MYDEQUE_H
