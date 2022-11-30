#include <iostream>
#include "node.h"
#include "xor_linked_list.h"
using namespace std;

int main()
{
    Node<int>* head = NULL;
    Node<int>* rear = get_rear(head);

    push_front(head,6);
    //head = pop_rear(head);
    head = pop_front(head);

    //cout << head << endl;

    push_front(head,7);
    //head = pop_rear(head);

    push_rear(head,1);

    push_front(head,8);
    push_front(head,9);
    push_rear(head,10);
    push_rear(head,14);
    push_rear(head,2);
    head = pop_front(head);


    //cout << "Head: " <<head->data <<endl;
    //cout << "Rear: " <<get_rear(head)->data <<endl;

    head = pop_rear(head);
    head = pop_rear(head);
    head = pop_front(head);
    push_rear(head,142);
    push_front(head,93);

    cout << "Head: " <<head->data <<endl;
    cout << "Rear: " <<get_rear(head)->data <<endl;
    //insert(&head, 20);
    //head = reverseLinkedList(head);
    printListRear(head);
    printList(head);
    //printListRear(head);
    //insert()
    return 0;
}
