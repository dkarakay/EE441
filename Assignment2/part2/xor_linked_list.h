#include <iostream>

using namespace std;


// LL Wrapper for Maze
template <class T>
class LL_wrapper
{
private:
    Node<T>* head;

public:
    LL_wrapper()
    {
        head = NULL;
    }
    void push_front(T data)
    {
        _push_front(head, data);
    }
    void push_rear(T data)
    {
        _push_rear(head, data);
    }

    T pop_rear()
    {
        return _pop_rear(head);
    }

    T pop_front()
    {
        return _pop_front(head);
    }

    T peek_front()
    {
        return _peek_front(head);
    }

    void print_elements()
    {
        _print_elements(head);
    }
};



template <class T>
Node<T>* get_rear(Node<T>* head)
{
    // If head is null -> empty list
    if(head == NULL)
    {
        return head;
    }

    // Else make currPtr to head, prevPtr to null
    Node<T>* currPtr = head;
    Node<T>* prevPtr = NULL;
    Node<T>* nextPtr ;


    // Traverse till reach to the end of the XORLinkedList
    while(currPtr != NULL)
    {
        nextPtr = Xor(prevPtr, currPtr->xnode);
        prevPtr = currPtr;
        currPtr = nextPtr;
    }
    // prevPtr shows the rear node
    return prevPtr;
}


// Push to the front of XORLinkedList
template <class T>
void _push_front (Node<T>* &head_ref, T data)
{
    // Create new node to hold passed data
    Node<T>* new_node = new Node<T>();
    new_node -> data = data;
    new_node -> xnode = head_ref;

    // If head_ref is not null, then set
    // head_ref->xcode to the XOR of new node and head_ref->xcode

    if(head_ref != NULL)
    {
        head_ref->xnode = Xor(new_node, head_ref->xnode);
    }

    // Set head_ref = new_node
    head_ref = new_node;


}


// Push to the rear of XORLinkedList
template <class T>
void _push_rear (Node<T>* &head_ref, T data)
{
    // Create new node to hold passed data
    Node<T>* new_node = new Node<T>();
    new_node -> data = data;

    // If head_ref is NULL, act like push_front
    if(head_ref == NULL)
    {
        new_node -> xnode = head_ref;
        head_ref = new_node;
    }

    else
    {
        // Get rear node
        Node<T>* rear = get_rear(head_ref);
        new_node -> xnode = rear;

        // set rear->xcode to the XOR of new node and rear->xcode
        if(rear != NULL)
        {
            rear->xnode = Xor(new_node, rear->xnode);
        }
        // set rear->xcode to the new node
        rear = new_node;
    }

}

// Pop Node from rear of XORLinkedList
template <class T>
T _pop_rear (Node<T>* &head_ref)
{
    Node<T>* currPtr = head_ref;
    Node<T>* prevPtr = NULL;
    Node<T>* nextPtr;

    // Popped Node
    T popData;

    // If head_ref == null print empty list
    if(currPtr == NULL)
    {
        return NULL;
    }

    // If linked list contains only one element
    else if(Xor(prevPtr, currPtr->xnode) == NULL)
    {

        // Return popped Node
        popData = currPtr->data;

        // make head_ref null and delete
        head_ref = NULL;
        delete (head_ref);
    }
    else
    {
        // Iterate till we reach last two elements of XORLinkedList
        while(Xor(prevPtr, currPtr->xnode) != NULL)
        {
            nextPtr = Xor(prevPtr, currPtr->xnode);
            prevPtr = currPtr;
            currPtr = nextPtr;

        }
        // Temp NULL node
        Node<T>* t = NULL;

        // Set prevPtr->xnode to the XOR based rule
        prevPtr->xnode = Xor(Xor(prevPtr->xnode, currPtr),t);


        // Return popped Node
        popData= currPtr->data;

        // Remove currPtr
        delete(currPtr);


    }

    // Return popped data
    return popData;
}

template <class T>
T _pop_front (Node<T>* &head_ref)
{
    Node<T>* currPtr = head_ref;
    Node<T>* prevPtr = NULL;
    Node<T>* nextPtr;

    // Popped Node
    T popData;

    // If head_ref == null print empty list
    if(head_ref == NULL)
    {
        //cout << "Empty List" << endl;
        return NULL;
    }

    // If linked list contains only one element
    else if(Xor(prevPtr, currPtr->xnode) == NULL)
    {
        // Return popped Node
        popData= currPtr->data;

        // make head_ref null and delete
        head_ref = NULL;
        delete (head_ref);
    }
    else
    {

        nextPtr = Xor(prevPtr, currPtr->xnode);
        prevPtr = currPtr;
        currPtr = nextPtr;
        nextPtr = Xor(prevPtr, currPtr->xnode);

        // prevPtr -> currPtr -> nextPtr
        // Delete PrevPtr and set head_ref to currPtr

        //cout << "Popped front: "<<  prevPtr->data <<endl;
        head_ref = currPtr;
        head_ref -> xnode = nextPtr;

        // Return popped Node
        popData = prevPtr->data;

        delete(prevPtr);
    }



    // Return modified head_ref
    return popData;
}


template <class T>
T _peek_front (Node<T>* &head_ref)
{
    Node<T>* currPtr = head_ref;
    Node<T>* prevPtr = NULL;
    Node<T>* nextPtr;

    // If head_ref == null print empty list
    if(head_ref == NULL)
    {
        return NULL;
    }

    // Return peek data
    return currPtr->data;
}


// Original printList but from front to rear
template <class T>
void _print_elements_original (Node<T>* head)
{
    Node<T>* currPtr = head;
    Node<T>* prevPtr = NULL;
    Node<T>* nextPtr ;

    // From top to rear
    while(currPtr != NULL)
    {
        cout << currPtr ->data << " ";
        nextPtr = Xor(prevPtr, currPtr->xnode);
        prevPtr = currPtr;
        currPtr = nextPtr;
    }
    cout << endl;

}


// Print from rear to front
template <class T>
void _print_elements(Node<T>* head)
{
    if(head == NULL)
    {
        _print_elements_original(head);
        return;
    }
    Node<T>* currPtr = head;
    Node<T>* prevPtr = NULL;
    Node<T>* nextPtr ;
    while(Xor(prevPtr, currPtr->xnode) != NULL)
    {
        nextPtr = Xor(prevPtr, currPtr->xnode);
        prevPtr = currPtr;
        currPtr = nextPtr;
    }
    // Reverse List and use _print_elements_original
    head = currPtr;
    _print_elements_original(head);
}


