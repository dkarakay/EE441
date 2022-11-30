#include <iostream>

using namespace std;

template <class T>
class Node
{

public:
    T data;
    Node<T>* xnode;
    //Node<T>* Xor(Node<T>* x, Node<T>* y);
    //void insert(Node<T>* &head_ref, T data);
    //void printList(Node<T>* head);
};


template <class T>
Node<T>* Xor(Node<T>* x, Node<T>* y)
{
    return reinterpret_cast<Node<T>*>(
               reinterpret_cast<uintptr_t>(x)
               ^ reinterpret_cast<uintptr_t>(y));

}
