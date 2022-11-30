#include <iostream>

using namespace std;

template <class T>
class Node
{

public:
    T data;
    Node<T>* xnode;
};


template <class T>
Node<T>* Xor(Node<T>* x, Node<T>* y)
{
    return reinterpret_cast<Node<T>*>(
               reinterpret_cast<uintptr_t>(x)
               ^ reinterpret_cast<uintptr_t>(y));

}
