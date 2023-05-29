#include "MyDeque.h"

template<class T>
DequeIterator<T> MyDeque<T>::begin() const
{
    Node<T>* first_node = front;
    return DequeIterator<T>(first_node,0);
}

template<class T>
DequeIterator<T> MyDeque<T>::end() const
{
    Node<T>* last_node = back;
    return DequeIterator<T>(last_node,last_node->count);
}


template<class T>
T& MyDeque<T>::_front()
{
    return front->data[0];
}

template<class T>
T& MyDeque<T>::_back()
{
    return back->data[back->count-1];
}

template<class T>
void MyDeque<T>::push_front(const T &value)
{
    if(frontInd==0)
    {
        resize(capacity*2);
    }
    --frontInd;
    _data[frontInd]=value;
    ++size;
}

template<class T>
void  MyDeque<T>::push_back(const T &value)
{
    if(size==capacity)
    {
        resize(capacity*2);
    }
    _data[frontInd+size]=value;
    ++size;
}

template<class T>
void MyDeque<T>::pop_front()
{
    if(size==0)
    {
        throw std::out_of_range("deque is empty");
    }
    ++frontInd;
    --size;
    if(size<=capacity/4 && capacity>8)
    {
        resize(capacity/2);
    }
}

template<class T>
void MyDeque<T>::pop_back()
{
    if(size==0)
    {
        throw std::out_of_range("deque is empty");
    }
    --size;
    if(size<=capacity/4 && capacity>8)
    {
        resize(capacity/2);
    }
}

template<class T>
[[nodiscard]] bool MyDeque<T>::empty() const
{
    return size==0;
}

template<class T>
[[nodiscard]] size_t MyDeque<T>::_size() const
{
    return size;
}

//template<class T>
//T& MyDeque<T>::operator[](int _index)
//{
//    if(_index==0&&_index>=size)
//    {
//        throw std::out_of_range("Index out of range");
//    }
//    Node<T>* _node = front;
//    while(_node!= nullptr&&frontInd+_node->count<_index)
//    {
//        _node
//    }
//}

template<class T>
[[noreturn]] void MyDeque<T>::clear()
{
    while(!empty())
    {
        pop_front();
    }
}
















