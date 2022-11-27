
#include "Disc.h"
#pragma once

using namespace std;

class Hanoi
{
private:
    Disc* rod0; // int -> Disc
    Disc* rod1;
    Disc* rod2;
    int num_discs;

public:
    int aux, fin, init = 0;
    Disc discs[];
    // the constructor for the class to initialize the game
    Hanoi(int num);
    Disc* get_rods(int rod_index); // int -> Disc
    int get_last_nonzero_index(int rod_index);
    int get_num_of_discs() const;
    void set_aux_fin();   // function necessary for solver
    void move(int from, int to);
    int nonzero_index(Disc* arr);
    //~Hanoi();
};


int dia_inc = 2; // global parameter for the diameter arrangements

// the constructor for Hanoi class, starter of the game
Hanoi::Hanoi(int num_of_discs)
{
    rod0 = new Disc[20]; // int -> Disc
    rod1 = new Disc[20];
    rod2 = new Disc[20];
    num_discs = num_of_discs;
    set_aux_fin(); // set aux and fin
    if (num_discs > 20)
    {
        cout << "not a valid number of discs, check again! " << endl;
        exit(0);
    }
    // create the discs with increase of two, store at an array
    for (int i = 0; i<num_of_discs; i++)
    {
        Disc temp(dia_inc*i + 1);
        //discs[i] = temp;
        /* accumulate at them at rod0 using diameters
           from small to large */
        rod0[num_of_discs - i - 1].set_diameter(temp.get_diameter()); // changed
    }
}
// destructor for the class
/*Hanoi::~Hanoi()
{
    delete[] rod0;
    delete[] rod1;
    delete[] rod2;
}
*/

// helper function
// get index of the last nonzero term of an array
int Hanoi::nonzero_index(Disc* arr) // bool parameter with ref
{
    //int arr_size = 20;
    for(int i = num_discs-1; i >= 0; i--)
    {
        if(arr[i].get_diameter() != 0)
        {
            return i;
        }
    }
    return 0;
}

// return the rod arrays as pointers
Disc* Hanoi::get_rods(int rod_index)
{
    if (rod_index == 0)
        return rod0;
    else if (rod_index == 1)
        return rod1;
    else if (rod_index == 2)
        return rod2;
    else
    {
        cout << "out" << endl;
        exit(0);
    }
}

/* get the index of the last disc with nonzero diameter
   for the rod with desired index */
int Hanoi::get_last_nonzero_index(int rod_index)
{
    return nonzero_index(get_rods(rod_index));
}

int Hanoi::get_num_of_discs() const
{
    return num_discs;
}

// set aux and fin for solver function
void Hanoi::set_aux_fin()
{
    aux = 1;
    fin = 2;
}

void Hanoi::move(int from, int to)
{
    int checkher = 1;
    int available, holder;
    // first check the indeces, then the legality of the movement
    try
    {
        if ((from < 3 && to < 3) && (from >= 0 && to >= 0))
        {
            if (get_last_nonzero_index(to) == 0 && get_rods(to)[get_last_nonzero_index(to)].get_diameter() == 0)  // changed
            {
                available = 1;
            }
            else if (get_rods(from)[get_last_nonzero_index(from)].get_diameter() < get_rods(to)[get_last_nonzero_index(to)].get_diameter())  // changed
            {
                available = 2;
            }
            else
            {
                available = 0;
                throw checkher;
            }
        }
        else
        {
            available = 0;
            throw checkher;
        }
    }
    catch (int checkher)
    {
        cout << "move is not valid, check again \n";
    }

    if (available == 1)
    {
        //  the move part is realized
        if (get_last_nonzero_index(to) != get_num_of_discs())   // checking whether full or not
        {
            get_rods(to)[get_last_nonzero_index(to)].set_diameter(get_rods(from)[get_last_nonzero_index(from)].get_diameter()); // changed
            //cout << " if ic1" << endl;
            holder = get_rods(from)[get_last_nonzero_index(from)].get_diameter(); // changed
            get_rods(from)[get_last_nonzero_index(from)].set_diameter(0); // changed
            //cout << " if ic2" << endl;
            /* get_rods(from)[get_last_nonzero_index(from)] gives the diameter of a disc,
               discs are called by their diameter values in my case */
        }
    }
    else if (available == 2)
    {
        //  the move part is realized
        if (get_last_nonzero_index(to) != (get_num_of_discs() - 1))   // checking whether full or not
        {
            get_rods(to)[get_last_nonzero_index(to) + 1].set_diameter(get_rods(from)[get_last_nonzero_index(from)].get_diameter()); // changed
            //cout << " if ic11" << endl;
            holder = get_rods(from)[get_last_nonzero_index(from)].get_diameter(); // changed
            get_rods(from)[get_last_nonzero_index(from)].set_diameter(0); // changed
            //cout << " if ic22" << endl;
        }
        /* get_rods(from)[get_last_nonzero_index(from)] gives the diameter of a disc,
           discs are called by their diameter values in my case */
    }
    else
    {
        cout << "out" << endl;
        //exit(0);
    }
    //cout << "Disc " << holder << " is moved from Rod " << from << " to Rod " << to << endl;
}
