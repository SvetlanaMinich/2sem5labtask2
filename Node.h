#ifndef DEQUE_NODE_H
#define DEQUE_NODE_H

template<class T>
class Node {
public:
    Node()
    {
        count=0;
        prev=nullptr;
        next=nullptr;
    }
    int count;
    Node<T>* prev;
    Node<T>* next;
    T* data = new T[4];
    ~Node()
    {
        delete prev;
        delete next;
        delete[] data;
    }
};


#endif //DEQUE_NODE_H
