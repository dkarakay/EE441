#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

using namespace std;


class Disc
{
private:
    int diameter=0; // Set initial diameter to zero
public:
    Disc(int d); //Constructor
    int getData(); //Get diameter data
};

class Hanoi
{
public:
    int number_of_disc=0; // number of disks
    int move_count=0; // Storing move count for fun
    int length_of_rods[3]; // Storing the length of each rod


    /*
    Using 2D array to store every value from the Rod arrays
    By doing that, I will be able to decrease the number of lines for my code
    while making my code cleaner to understand.

    After calling move(), I will replace Rod arrays with the results from all_rods array.
    copying_array_from_all_rods() function can be examined for further details.
    */
    int all_rods[3][20];

    // Arrays with full of Disc objects
    Disc* rod0[20];
    Disc* rod1[20];
    Disc* rod2[20];

    // Constructor for Hanoi
    Hanoi (int n);

    // Move function
    void move(int from, int to);
    void print_rods();
    void copying_array_from_all_rods(bool c);

};

Disc::Disc(int d)
{
    // Constructor for Disc class
    // Set Input d to diameter variable of a Disc object
    diameter = d;
}

int Disc::getData()
{
    // Retrieving diameter data
    return diameter;
}


Hanoi::Hanoi(int n)
{
    // Constructor for Hanoi class
    number_of_disc = n;

    // Print the number of disc
    cout << number_of_disc << endl;

    // Resetting all array to zero
    for(int i=0; i<20; i++)
    {
        all_rods[0][i] = 0;
        all_rods[1][i] = 0;
        all_rods[2][i] = 0;
        rod0[i] = new Disc(0);
        rod1[i] = new Disc(0);
        rod2[i] = new Disc(0);
    }

    // Putting n different type of Disc to Rod 0
    for(int i=number_of_disc-1; i>=0; i--)
    {
        rod0[i] = new Disc(number_of_disc-i);
    }

    // Setting the lengths for each Rod (0 if all elements are zero)
    length_of_rods[0] = number_of_disc;
    length_of_rods[1] = 0;
    length_of_rods[2] = 0;

    // Copy data from Rods array to all_rods 2D array
    copying_array_from_all_rods(false);

}

void Hanoi::copying_array_from_all_rods(bool check)
{

    if(check == false)
        // If check = false, then copy from Rod(0,1,2) array to all_rods 2D Array
    {
        for(int j = 0; j < length_of_rods[0]; j++)
        {
            all_rods[0][j] = (*rod0[j]).getData();
        }

        for(int j = 0; j < length_of_rods[1]; j++)
        {
            all_rods[1][j] = (*rod1[j]).getData();
        }

        for(int j = 0; j < length_of_rods[2]; j++)
        {
            all_rods[2][j] = (*rod2[j]).getData();
        }
    }
    else
        // Copy from all_rods 2D array to Rod(0,1,2) arrays
        // This part is utilized after the move function
    {
        for(int j = 0; j < 20; j++)
        {
            *rod0[j] = Disc(all_rods[0][j]);
            *rod1[j] = Disc(all_rods[1][j]);
            *rod2[j] = Disc(all_rods[2][j]);
        }

    }
}

void Hanoi::print_rods()
{
    // Print the current situation of rods

    for(int i = 19; i>=0; i--)
    {

        // Getting the Disk diameter from each rod in a for loop
        int rod0_val = (*rod0[i]).getData();
        int rod1_val = (*rod1[i]).getData();
        int rod2_val = (*rod2[i]).getData();

        // If sum of each value is not zero, this means we do not have a zero row. Since all numbers are positive, if we have a zero row, we do not need to print them.
        if(rod0_val+rod1_val+rod2_val != 0)
        {
            cout << rod0_val << " - " << rod1_val << " - " << rod2_val << endl;
        }
    }
}

void Hanoi::move(int from, int to)
{
    // Move one disc to another


    // If the length of from rod is zero (empty) or length of to rod is equal to 20 (full) print invalid move and return
    if(length_of_rods[from] == 0 || length_of_rods[to] == 20 )
    {
        cout << "Invalid move" << endl;
        return;
    }

    // Holding the diameter value of disc of from rod
    int from_disc = 0;

    // Holding the diameter value of disc of to rod
    int to_disc = 0;

    // Getting the length of from & to rods
    int from_rod_max_index = length_of_rods[from];
    int to_rod_max_index = length_of_rods[to];


    // If length is greater than 0, we need to subtract 1 from the lengths to get indexes
    if(from_rod_max_index > 0)
    {
        from_rod_max_index -= 1;
    }
    if(to_rod_max_index > 0)
    {
        to_rod_max_index -= 0;
    }

    // Getting the diameter value of the top element of from & to rods
    from_disc = all_rods[from][from_rod_max_index];
    to_disc = all_rods[to][to_rod_max_index];

    // If diameter value of to_disc is zero, which means we can make a move
    // Second condition is that if to_disc is not zero, then from_disc should be greater than to_disc so that move can be valid
    if(to_disc == 0 || (to_disc != 0 && from_disc < to_disc))
    {
        // Resetting from_disc place to 0
        all_rods[from][from_rod_max_index] = 0;

        // Sending from_disc to its new place
        all_rods[to][to_rod_max_index] = from_disc;

        // Decrementing the length of from rod
        length_of_rods[from] -=1;

        //Incrementing the length of to rod
        length_of_rods[to] +=1;

        cout << "Disc " << from_disc << " is moved from Rod " << from << " to Rod " << to <<endl;
    }
    else
    {
        cout << "Invalid move" << endl;
        return;
    }

    // Copying from all_rods to Rod arrays
    copying_array_from_all_rods(true);

    // Printing from Rod arrays to see the result
    print_rods();

    // Increment move count
    move_count +=1;

}




void solve_hanoi_by_recursion(Hanoi &game,int number_of_disc, int from_rod, int to_rod,
                              int middle_rod)
{

    // If all discs move to to_rod, return
    if (number_of_disc == 0)
    {
        cout << "Move count: " << game.move_count << endl;

        return;
    }

    // Call recursively to move each Disc to middle one (middle one is the target)
    solve_hanoi_by_recursion(game,number_of_disc - 1, from_rod, middle_rod, to_rod);
    game.move(from_rod,to_rod);

    //Continue recursively to move all discs to to_rod
    solve_hanoi_by_recursion(game,number_of_disc - 1, middle_rod, to_rod, from_rod);
}

void solve_hanoi(Hanoi& game)
{
    solve_hanoi_by_recursion(game, game.number_of_disc,0,2,1);
}



#endif // TEST_H_INCLUDED
