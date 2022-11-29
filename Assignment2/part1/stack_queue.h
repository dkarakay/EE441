#define SIZE 5000
using namespace std;

template <class T> class StackQueue
{

public:
    StackQueue();

    void push_rear(T el);
    void push_front(T el);

    T pop_rear();
    T pop_front();
    T peek_front();

    void print_elements();
    void move_all_elements(bool right);
    bool is_full();
    int get_size();

private:
    int top;
    int tail;
    T stqu[SIZE];


};

template <class T> StackQueue<T>::StackQueue()
{
    top = -1;
    tail = 0;
}

template <class T> void StackQueue<T>::push_front(T k)
{

    if (is_full())
    {
        // Display message when no elements can be pushed
        // into it
       // cout << "StackQueue is full\n";
        return;
    }

    //cout << "Pushed front: " << k << endl;

    top = top + 1;

    // Now, adding element to stack
    stqu[top] = k;
    //print_elements();
}



template <class T> void StackQueue<T>::push_rear(T val)
{

    if (is_full())
    {
    //    cout << "StackQueue is full\n";
        return;
    }

   // cout << "Pushed rear: " << val << endl;


    move_all_elements(true);

    top = top + 1;
    stqu[tail] = val;
    //print_elements();
}

template <class T> bool StackQueue<T>::is_full()
{
    if (top != (SIZE - 1))
        return 0;
    return 1;
}

template <class T> void StackQueue<T>::print_elements()
{
   // cout << "Tail: "<< stqu[tail] << " Top: " << stqu[top] << endl;
    cout <<"SQ: ";
    for(int i = tail; i<get_size(); i++)
    {
        cout << stqu[i];
    }
    cout << endl;
}

template <class T> T StackQueue<T>::pop_front()
{
    T pfront = stqu[top];
    top--;
   // cout << "Popped from front: " << pfront << endl;
    //print_elements();
    return pfront;
}

template <class T> T StackQueue<T>::pop_rear()
{
    T prear = stqu[tail];
    tail++;
    //cout << "Popped from rear: " << prear << endl;
    //print_elements();
    return prear;
}

template <class T> T StackQueue<T>::peek_front()
{
    return stqu[top];
}

template <class T> int StackQueue<T>::get_size()
{
    return top+1;
}
template <class T> void StackQueue<T>::move_all_elements(bool right)
{
    if(right)
    {
        for(int i = get_size(); i>tail; i--)
        {
            stqu[i] = stqu[i-1];

        }
    }
}
