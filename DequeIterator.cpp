#include "DequeIterator.h"

template<class T>
T& DequeIterator<T>::operator*() const
{
    return node->data[index];
}

template<class T>
T* DequeIterator<T>::operator->() const
{
    return &(node->data[index]);
}

template<class T>
DequeIterator<T>& DequeIterator<T>::operator++()
{
    ++index;
    if(index==node->count)
    {
        node=node->next;
        index=0;
    }
    return *this;
}

template<class T>
DequeIterator<T> DequeIterator<T>::operator++(int n)
{
    DequeIterator<T> buf = *this;
    ++(*this);
    return buf;
}

template<class T>
DequeIterator<T>& DequeIterator<T>::operator--()
{
    if(index==0)
    {
        node=node->prev;
        index=node->count-1;
    }
    else
    {
        --index;
    }
    return *this;
}

template<class T>
DequeIterator<T> DequeIterator<T>::operator--(int n)
{
    DequeIterator<T> buf = *this;
    --(*this);
    return buf;
}

template<class T>
DequeIterator<T> DequeIterator<T>::operator-(int n) const
{
    DequeIterator<T> buf = *this;
    buf-=n;
    return buf;
}

template<class T>
DequeIterator<T> DequeIterator<T>::operator+(int n) const
{
    DequeIterator<T> buf = *this;
    buf+=n;
    return buf;
}

template<class T>
int DequeIterator<T>::operator-(const DequeIterator<T> &_other) const
{
    int n = 0;
    DequeIterator<T> buf = *this;
    while(buf!=_other)
    {
        if(buf>_other)
        {
            --buf;
        }
        else
        {
            buf++;
        }
        n++;
    }
    return n;
}

template<class T>
bool DequeIterator<T>::operator==(const DequeIterator<T> &_other) const
{
    return (node==_other.node)&&(index==_other.index);
}

template<class T>
bool DequeIterator<T>::operator!=(const DequeIterator<T> &_other) const
{
    return (node!=_other.node)||(index!=_other.index);
}

template<class T>
bool DequeIterator<T>::operator<(const DequeIterator<T> &_other) const
{
    if(node==_other.node)
    {
        return index<_other.index;
    }
    else
    {
        return node<_other.node;
    }
}

template<class T>
bool DequeIterator<T>::operator>(const DequeIterator<T> &_other) const
{
    if(node==_other.node)
    {
        return index>_other.index;
    }
    else
    {
        return node>_other.node;
    }
}

template<class T>
DequeIterator<T>& DequeIterator<T>::operator+=(int n)
{
    if(n>=0)
    {
        int step=n/node->count;
        int steps=n%node->count;
        for(int i=0;i<step;i++)
        {
            node=node->next;
            index=0;
        }
        index+=steps;
        if(index>=node->count)
        {
            node=node->next;
            index=node->prev->count;
        }
    }
    else
    {
        int step=(-n)/node->count;
        int steps=(-n)%node->count;
        for(int i=0;i<step;i++)
        {
            node=node->prev;
            index=node->count-1;
        }
        index-=steps;
        if(index<0)
        {
            node=node->prev;
            index+=node->count;
        }
    }
    return *this;
}

template<class T>
DequeIterator<T>& DequeIterator<T>::operator-=(int n)
{
    return *this+=(-n);
}





