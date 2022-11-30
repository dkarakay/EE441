#include <iostream>
#include "node.h"
#include "maze.h"
#include "xor_linked_list.h"
using namespace std;


void solver(Maze &m)
{
    // LL Part
    cout << "First Pass:" << endl;

    LL_wrapper<char> ll = LL_wrapper<char>();
    ll.print_elements();
    m.print_state();

    // Iterate till the maze is solved
    while(!m.is_solved())
    {

        // If robot can move left, then move left
        if(m.can_move_left())
        {
            m.move_left();
            char temp = ll.peek_front();

            // If the previous movement was B, make simplification
            if(temp == 'B')
            {
                ll.pop_front();
                char temp2 = ll.pop_front();
                if(temp2 == 'L')
                {
                    ll.push_front('F');
                }
                else if(temp2 == 'F')
                {
                    ll.push_front('R');
                }
                else if(temp2 == 'R')
                {
                    ll.push_front('B');
                }
            }
            else
            {
                ll.push_front('L');
            }
        }

        // If robot can move forward, then move forward
        else if(m.can_move_forward())
        {
            m.move_forward();
            char temp = ll.peek_front();

            // If the previous movement was B, make simplification
            if(temp == 'B')
            {
                ll.pop_front();
                char temp2 = ll.pop_front();
                if(temp2 == 'L')
                {
                    ll.push_front('R');
                }
                else if(temp2 == 'F')
                {
                    ll.push_front('B');
                }

            }
            else
            {
                ll.push_front('F');
            }
        }

        // If robot can move right, then move right
        else if(m.can_move_right())
        {
            m.move_right();
            char temp = ll.peek_front();


            // If the previous movement was B, make simplification
            if(temp == 'B')
            {
                ll.pop_front();
                char temp2 = ll.pop_front();
                if(temp2 == 'L')
                {
                    ll.push_front('B');
                }


            }
            else
            {
                ll.push_front('R');
            }
        }
        // Else move back
        else
        {
            m.move_back();
            ll.push_front('B');

        }
        ll.print_elements();
        m.print_state();

    }
    cout << "Maze is solved."<<endl;

    // LL continues
    cout << "Second pass:" << endl;

    m = Maze();
    ll.print_elements();
    m.print_state();
    while(!m.is_solved())
    {
        char step = ll.pop_rear();
        if(step == 'L') m.move_left();
        if(step == 'F') m.move_forward();
        if(step == 'R') m.move_right();
        ll.print_elements();
        m.print_state();
    }


}


int main()
{
    Maze maz = Maze();
    solver(maz);



    /* Test for LL_wrapper
    LL_wrapper<char> ll = LL_wrapper<char>();
    ll.print_elements();
    ll.push_front('6');
    ll.print_elements();
    ll.push_front('a');
    ll.print_elements();
    ll.push_rear('c');
    ll.print_elements();
    ll.push_rear('z');
    ll.print_elements();

    cout << ll.peek_front() << endl;
    ll.print_elements();
    ll.pop_front();
    ll.print_elements();
    ll.push_rear('1');
    ll.print_elements();
    ll.pop_rear();
    ll.print_elements();
    ll.pop_rear();
    ll.print_elements();
    ll.pop_front();
    ll.print_elements();
*/

    return 0;
}
