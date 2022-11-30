#include <iostream>
#include <fstream>
#include "stack_queue.h"
#include "maze.h"

using namespace std;


void solver(Maze &m)
{
    // Stack Part
    cout << "First Pass:" << endl;

    StackQueue<char> sq;
    sq.print_elements();
    m.print_state();

    // Iterate till the maze is solved
    while(!m.is_solved())
    {

        // If robot can move left, then move left
        if(m.can_move_left())
        {
            m.move_left();
            char temp = sq.peek_front();

            // If the previous movement was B, make simplification
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

        // If robot can move forward, then move forward
        else if(m.can_move_forward())
        {
            m.move_forward();
            char temp = sq.peek_front();

            // If the previous movement was B, make simplification
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

        // If robot can move right, then move right
        else if(m.can_move_right())
        {
            m.move_right();
            char temp = sq.peek_front();


            // If the previous movement was B, make simplification
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
        // Else move back
        else
        {
            m.move_back();
            sq.push_front('B');

        }
        sq.print_elements();
        m.print_state();

    }
    cout << "Maze is solved."<<endl;

    // Queue Part
    cout << "Second pass:" << endl;

    m = Maze();
    sq.print_elements();
    m.print_state();
    while(!m.is_solved())
    {
        char step = sq.pop_rear();
        if(step == 'L') m.move_left();
        if(step == 'F') m.move_forward();
        if(step == 'R') m.move_right();
        sq.print_elements();
        m.print_state();
    }


}

int main()
{

    Maze maz = Maze();
    solver(maz);



    // Test for StackQueue
    /*
        StackQueue<int> sq;

        sq.print_elements();
        sq.push_front(1);

        sq.print_elements();
        sq.push_front(2);

        sq.print_elements();
        sq.push_rear(3);

        sq.print_elements();
        sq.push_front(4);

        sq.print_elements();
        sq.push_front(5);
        cout << "Peek: "<<sq.peek_front() << endl;

        sq.print_elements();
        sq.push_rear(6);

        sq.print_elements();
        int a = sq.pop_front();
        cout << a<< endl;

        sq.print_elements();
        int b = sq.pop_rear();
        cout << b << endl;

        sq.print_elements();
        sq.push_rear(7);

        sq.print_elements();
        sq.push_rear(8);

        sq.print_elements();
        sq.pop_front();

        sq.print_elements();
        sq.pop_front();

        sq.print_elements();
        sq.pop_rear();

        sq.print_elements();
        cout << "Peek: "<<sq.peek_front() << endl;
        sq.print_elements();

    */

    return 0;

}
