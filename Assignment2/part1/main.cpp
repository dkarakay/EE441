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
    return 0;
}
