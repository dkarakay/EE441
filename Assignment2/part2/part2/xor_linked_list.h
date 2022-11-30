#include <iostream>

using namespace std;

template <class T>
Node<T>* get_rear(Node<T>* head)
{
    // If head is null -> empty list
    if(head == NULL)
    {
        cout << "Empty list"<<endl;
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
void push_front (Node<T>* &head_ref, T data)
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
    cout << "Pushed front: " << data << endl;

    // Print List
    printList(head_ref);
}


// Push to the rear of XORLinkedList
template <class T>
void push_rear (Node<T>* &head_ref, T data)
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
    cout << "Pushed rear: " << data << endl;

    // Print List
    printList(head_ref);
}

// Pop Node from rear of XORLinkedList
template <class T>
Node<T>* pop_rear (Node<T>* &head_ref)
{
    Node<T>* currPtr = head_ref;
    Node<T>* prevPtr = NULL;
    Node<T>* nextPtr;

    // Popped Node
    Node<T>* popPtr = new Node<T>();

    // If head_ref == null print empty list
    if(currPtr == NULL)
    {
        cout << "Empty list" << endl;
    }

    // If linked list contains only one element
    else if(Xor(prevPtr, currPtr->xnode) == NULL)
    {
        cout << "Popped rear: " <<currPtr->data << endl;
        // make head_ref null and delete

        // Return popped Node
        popPtr->data = currPtr->data;
        popPtr->xnode = currPtr->xnode;

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
        cout << "Popped rear "<< currPtr->data << endl;

        // Set prevPtr->xnode to the XOR based rule
        prevPtr->xnode = Xor(Xor(prevPtr->xnode, currPtr),t);


        // Return popped Node
        popPtr->data = currPtr->data;
        popPtr->xnode = currPtr->xnode;

        // Remove currPtr
        delete(currPtr);


    }

    // Print List
    printList(head_ref);

    // Return modified head_ref
    return popPtr;
}

template <class T>
Node<T>* pop_front (Node<T>* &head_ref)
{
    Node<T>* currPtr = head_ref;
    Node<T>* prevPtr = NULL;
    Node<T>* nextPtr;

    // Popped Node
    Node<T>* popPtr = new Node<T>();

    // If head_ref == null print empty list
    if(head_ref == NULL)
    {
        cout << "Empty List" << endl;
    }

    // If linked list contains only one element
    else if(Xor(prevPtr, currPtr->xnode) == NULL)
    {
        cout << "Popped front: " <<currPtr->data << endl;

        // Return popped Node
        popPtr->data = currPtr->data;
        popPtr->xnode = currPtr->xnode;

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

        cout << "Popped front: "<<  prevPtr->data <<endl;
        head_ref = currPtr;
        head_ref -> xnode = nextPtr;

        // Return popped Node
        popPtr->data = prevPtr->data;
        popPtr->xnode = prevPtr->xnode;

        delete(prevPtr);
    }

    // Print List
    printList(head_ref);

    // Return modified head_ref
    return popPtr;
}


template <class T>
Node<T>* peek_front (Node<T>* &head_ref)
{
    Node<T>* currPtr = head_ref;
    Node<T>* prevPtr = NULL;
    Node<T>* nextPtr;

    // If head_ref == null print empty list
    if(head_ref == NULL)
    {
        cout << "Empty List" << endl;
    }

    cout << "Peek front " << currPtr->data<<endl;
    // Print List
    printList(head_ref);

    // Return modified head_ref
    return currPtr;
}


// Original printList but from front to rear
template <class T>
void printListOriginal (Node<T>* head)
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
void printList(Node<T>* head)
{
    if(head == NULL)
    {
        printListOriginal(head);
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
    // Reverse List and use PrintListOriginal
    head = currPtr;
    printListOriginal(head);
}


