#include <iostream>

using namespace std;



template <class T>
void push_front (Node<T>* &head_ref, T data)
{
    Node<T>* new_node = new Node<T>();
    new_node -> data = data;

    new_node -> xnode = head_ref;

    if(head_ref != NULL)
    {
        head_ref->xnode = Xor(new_node, head_ref->xnode);
    }
    head_ref = new_node;
    cout << "Pushed front: " << data << endl;

    printList(head_ref);
}

template <class T>
Node<T>* get_rear(Node<T>* head)
{
    Node<T>* currPtr = head;
    Node<T>* prevPtr = NULL;
    Node<T>* nextPtr ;


    while(currPtr != NULL)
    {

        nextPtr = Xor(prevPtr, currPtr->xnode);
        prevPtr = currPtr;
        currPtr = nextPtr;
    }
    return prevPtr;
}


template <class T>
void push_rear (Node<T>* &head_ref, T data)
{

    Node<T>* rear = get_rear(head_ref);

    Node<T>* new_node = new Node<T>();
    new_node -> data = data;
    new_node -> xnode = rear;

    if(rear != NULL)
    {
        rear->xnode = Xor(new_node, rear->xnode);
    }
    rear = new_node;
    cout << "Pushed rear: " << data << endl;
    printList(head_ref);

}

template <class T>
Node<T>* pop_rear (Node<T>* head)
{
    Node<T>* currPtr = head;
    Node<T>* prevPtr = NULL;
    Node<T>* nextPtr;

    if(currPtr == NULL)
    {
        cout << "Empty" << endl;
        return head;
    }
    if(Xor(prevPtr, currPtr->xnode) == NULL)
    {
        cout << "Pop one element" << endl;
        currPtr = NULL;
        delete (head);
        return head;
    }

    while(Xor(prevPtr, currPtr->xnode) != NULL)
    {
        nextPtr = Xor(prevPtr, currPtr->xnode);
        prevPtr = currPtr;
        currPtr = nextPtr;

    }
    Node<T>* t = NULL;
    cout << "Popped rear "<< currPtr->data << endl;
    prevPtr->xnode = Xor(Xor(prevPtr->xnode, currPtr),t);

    delete(currPtr);
    printList(head);

    return head;
}

template <class T>
Node<T>* pop_front (Node<T>* &head_ref)
{
    Node<T>* currPtr = head_ref;
    Node<T>* prevPtr = NULL;
    Node<T>* nextPtr;

    if(head_ref == NULL)
    {
        cout << "Empty" << endl;
    }
    if(Xor(prevPtr, currPtr->xnode) == NULL)
    {
        cout << "Popped front: " <<currPtr->data << endl;
        head_ref = NULL;
        delete (head_ref);
    }
    else
    {

        nextPtr = Xor(prevPtr, currPtr->xnode);
        prevPtr = currPtr;
        currPtr = nextPtr;
        nextPtr = Xor(prevPtr, currPtr->xnode);

        cout << "Popped front: "<<  prevPtr->data <<endl;
        /*    cout << "Popped front: "<<  currPtr->data <<endl;
            cout << "Popped front: "<<  nextPtr->data <<endl;
        */
        head_ref = currPtr;
        head_ref -> xnode = nextPtr;
        /*cout << "New head: "<<  head_ref <<endl;
        cout << "New head: "<<  head_ref ->xnode <<endl;
        cout << "New head: "<<  head_ref-> data<<endl;
        cout << "New head: "<<  head_ref ->xnode -> data<<endl;
        cout << "New head: "<<  head_ref <<endl;*/
        delete(prevPtr);
    }
    printList(head_ref);
    return head_ref;
}


template <class T>
void printList (Node<T>* head)
{
    Node<T>* currPtr = head;
    Node<T>* prevPtr = NULL;
    Node<T>* nextPtr ;

//    cout << "The nodes of Linked List are" << ;
    while(currPtr != NULL)
    {
        cout << currPtr ->data << " ";
        nextPtr = Xor(prevPtr, currPtr->xnode);
        prevPtr = currPtr;
        currPtr = nextPtr;
    }
    cout << endl;
}


template <class T>
Node<T>* reverseLinkedList(Node<T>* &head_ref)
{
    Node<T>* currPtr = head_ref;
    Node<T>* prevPtr = NULL;
    Node<T>* nextPtr ;
    while(Xor(prevPtr, currPtr->xnode) != NULL)
    {
        nextPtr = Xor(prevPtr, currPtr->xnode);
        prevPtr = currPtr;
        currPtr = nextPtr;
    }
    head_ref = currPtr;
    return head_ref;
}

template <class T>
void printListRear (Node<T>* head)
{
    head = reverseLinkedList(head);
    printList(head);
    head = reverseLinkedList(head);

}
