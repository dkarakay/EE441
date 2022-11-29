// Size can be modified
#define SIZE 1025

using namespace std;

template <class T> class StackQueue
{

public:
    StackQueue();

    void push_rear(T val);
    void push_front(T val);

    T pop_rear();
    T pop_front();
    T peek_front();

    void print_elements();
    void move_all_elements();
    bool is_full();
    int get_size();

private:
    int top;
    int tail;
    T stqu[SIZE];


};

// Initialize Stack Queue
template <class T> StackQueue<T>::StackQueue()
{
    // Make top=-1 and tail=0
    top = -1;
    tail = 0;
}

// Push element to front
template <class T> void StackQueue<T>::push_front(T val)
{

    if (is_full())
    {
        return;
    }
    // Increment top by 1, since we added a new element
    top = top + 1;

    // Push element to front of SQ
    stqu[top] = val;
}


// Push element to rear
template <class T> void StackQueue<T>::push_rear(T val)
{

    if (is_full())
    {
        return;
    }

    // Move all elements to make tail zero
    move_all_elements(true);

    // Increment top by 1, since we moved every element
    top = top + 1;

    // Push element to rear of SQ
    stqu[tail] = val;
}

// If the Stack is full
template <class T> bool StackQueue<T>::is_full()
{
    if (top != (SIZE - 1))
        return 0;
    return 1;
}

// Print all elements
template <class T> void StackQueue<T>::print_elements()
{
    cout <<"SQ: ";
    if(get_size()-tail==0){
        cout << " ";
    }
    for(int i = tail; i<get_size(); i++)
    {
        cout << stqu[i];
    }
    cout << endl;
}

// Pop from front
template <class T> T StackQueue<T>::pop_front()
{
    // Get element from Top
    T pfront = stqu[top];

    // Decrement top by 1
    top--;
    return pfront;
}

// Pop from rear
template <class T> T StackQueue<T>::pop_rear()
{
    // Get element from tail
    T prear = stqu[tail];

    // Increment tail by 1
    tail++;

    return prear;
}

// Get Front element
template <class T> T StackQueue<T>::peek_front()
{
    return stqu[top];
}

// Get size of stackqueue (only pushed elements)
template <class T> int StackQueue<T>::get_size()
{
    return top+1;
}

// This is for creating a space at tail
// Move every element to next index and make original tail to be zero
template <class T> void StackQueue<T>::move_all_elements()
{

    for(int i = get_size(); i>tail; i--)
    {
        stqu[i] = stqu[i-1];

    }

}
