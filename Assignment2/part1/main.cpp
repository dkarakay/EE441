#include <iostream>
#include <fstream>
#include "stack_queue.h"
#include "maze.h"

using namespace std;


void solver(Maze &m)
{
    StackQueue<char> sq;
    sq.print_elements();
    m.print_state();
    while(!m.is_solved())
    {

        if(m.can_move_left())
        {
            m.move_left();
            char temp = sq.peek_front();
            if(temp == 'B')
            {
                sq.pop_front();
                char temp2 = sq.pop_front();
                if(temp2 == 'L')
                {
                    sq.push_front('F');
                }
                else if(temp2 == 'F')
                {
                    sq.push_front('R');
                }
                else if(temp2 == 'R')
                {
                    sq.push_front('B');
                }
            }
            else
            {
                sq.push_front('L');
            }
        }
        else if(m.can_move_forward())
        {
            m.move_forward();
            char temp = sq.peek_front();
            if(temp == 'B')
            {
                sq.pop_front();
                char temp2 = sq.pop_front();
                if(temp2 == 'L')
                {
                    sq.push_front('R');
                }
                else if(temp2 == 'F')
                {
                    sq.push_front('B');
                }

            }
            else
            {
                sq.push_front('F');
            }
        }

        else if(m.can_move_right())
        {
            m.move_right();
            char temp = sq.peek_front();
            if(temp == 'B')
            {
                sq.pop_front();
                char temp2 = sq.pop_front();
                if(temp2 == 'L')
                {
                    sq.push_front('B');
                }


            }
            else
            {
                sq.push_front('R');
            }
        }
        else
        {
            m.move_back();
            cout << 'stuck' << endl;
            sq.push_front('B');

        }
        sq.print_elements();
        m.print_state();

    }

}

int main()
{

    /*StackQueue<int> ints;

    ints.push_front(1);
    ints.push_front(2);
    ints.push_rear(3);
    ints.push_front(4);
    ints.push_front(5);
    cout << "Peek: "<<ints.peek_front() << endl;
    ints.push_rear(6);
    int a = ints.pop_front();
    cout << a<< endl;
    int b = ints.pop_rear();
    cout << b << endl;
    ints.push_rear(7);
    ints.push_rear(8);
    ints.pop_front();
    ints.pop_front();
    ints.pop_rear();
    cout << "Peek: "<<ints.peek_front() << endl;
    /*
    Maze maz = Maze();
    maz.print_state();
    /* cout << endl;
    cout << "Can move left: " << boolalpha << maz.can_move_left() << endl;
    cout << "Can move right: " << boolalpha << maz.can_move_right() << endl;
    cout << "Can move forward: " << boolalpha << maz.can_move_forward() << endl;
    cout << "Can move back: " << boolalpha << maz.can_move_back() << endl;
    */


    Maze maz = Maze();
    //maz.print_state();

    //   maz.move_left();
    // maz.move_left();
    // maz.move_forward();
    // maz.move_forward();
    // maz.move_forward();
    // maz.move_back();
    // maz.move_forward();
    // maz.move_right();
    // maz.move_forward();
    // maz.move_right();
    // maz.move_left();
    //maz.move_forward();
    // cout << "Is solved: " <<boolalpha << maz.is_solved() << endl;;
    // maz.move_left();
    // maz.move_forward();
    // maz.move_forward();
    // maz.move_right();
    // maz.move_forward();
    // maz.move_forward();
    // maz.move_forward();
    // maz.move_left();
    // maz.move_forward();
    // cout << "Is solved: " <<boolalpha << maz.is_solved() << endl;


    solver(maz);
    return 0;
}
