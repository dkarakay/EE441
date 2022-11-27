#include <iostream>
#include "Discs.h"
# pragma once
using namespace std;

// Defining variables to set the diameters of the Discs that are
// initialized when a new object of Hanoi class is created.

int coef = 1;
int offset = 1;

// Defining the private and public members of the Hanoi Class
class Hanoi
{
private:

    int rod0[20] = {0}, rod1[20] = {0},
        rod2[20] = {0}, all_discs[20] = {0};


public:
    int num_disc[3] = {0};
    int disc_quantity = 0;
    Hanoi(int no_disc);
    int Get_Diameter(int index, int row);
    int Disc_Storage(int member);
    void move(int from, int to);
    int rod0_disc_quantity();


};

// Constructor of the Hanoi Class. Initializing a game depending
// on the number of Discs. Diameters of the Discs are dependent
// on the "coef" variable and an offset.
Hanoi::Hanoi(int no_disc) {
    num_disc[0] = no_disc;
    disc_quantity = no_disc;
    for(int i = 0; i < disc_quantity; i++){
        Discs Disc(coef*i + offset);
        rod0[num_disc[0] - 1 - i] = Disc.Get_Diameter();
        all_discs[num_disc[0] - 1 - i] = (coef*i) + offset;
    }
    for(int i = 0; i < disc_quantity; i++){
        cout << "Disc" << i << ": " << rod0[i] << endl;
    }
}
// Disc_Storage function returns an array which contains the diameter information
// of the discs. In other words, the function returns the initial state of the rod[0]
int Hanoi::Disc_Storage(int member_number){
    return all_discs[member_number];
}

// Get_Diameter function returns the diameter of a disc from a specific rod and index.
// For example, user can obtain the diameter of the second disc at rod1 by giving
// inputs index = 1, row = 2.
int Hanoi::Get_Diameter(int index, int row){

    switch(index) {
        case 0:
            return rod0[row];
        case 1:
            return rod1[row];
        case 2:
            return rod2[row];
    }
    return 0;
}

// Move function, simply moves a disk from a rod to another. Rods are defined as
// arrays and this function resets the non-zero element which has the highest index
// (diameter = 0 means that there is no disc) and writes the diameter information
// to another rod array.
void Hanoi::move(int from, int to){

    int state;

    // There are 6 (3! = 3*2*1) cases for move function.

    if(from == 0 && to == 1){ state = 0;}
    else if(from == 0 && to == 2){ state = 1;}
    else if(from == 1 && to == 0){ state = 2;}
    else if(from == 1 && to == 2){ state = 3;}
    else if(from == 2 && to == 0){ state = 4;}
    else if(from == 2 && to == 1){ state = 5;}
    // If the inputs do not point out to any of the above states,
    // Then the operation is not a valid operation.
    else{cerr << "invalid operation" << endl; exit(0);}

// Writing the "move" algorithm for each case.
    switch(state) {
        case 0:
            // For case 0, a disc is moved from rod 0 to rod 1.
            // If the number of discs at rod1 is equal to 0 and the number
            // of discs at rod0 is non-zero. Then, the moving is legal.
            if(num_disc[1] == 0 && rod0[0] != 0){
                // incrementing the number of discs at rod1
                num_disc[1]++;
                // Writing the diameter information on rod1
                rod1[num_disc[1] - 1] = rod0[num_disc[0] - 1];
                // Resetting the diameter of the highest disc at rod0
                // Then decrementing the number of discs at rod0
                rod0[num_disc[0] - 1] = 0; num_disc[0]--;
                //cout << "Disc " << Get_Diameter(1,num_disc[1] - 1) <<
                //     " is moved from rod0 to rod1" << endl;
            }
            //
            else if(rod0[num_disc[0] - 1] < rod1[num_disc[1] - 1] && num_disc[1] > 0 && num_disc[0] > 0){
                // Same move operation is legal for the case when the diameter of the highest disc
                // rod0 is smaller than the diameter of the highest disc at rod1. Still, the number
                // of discs at rod0 must be non-zero.
                num_disc[1]++;
                rod1[num_disc[1] - 1] = rod0[num_disc[0] - 1];
                rod0[num_disc[0] - 1] = 0; num_disc[0]--;
                //cout << "Disc " << Get_Diameter(1,num_disc[1] - 1) <<
                //     " is moved from rod0 to rod1" << endl;
            }
            else{
                // If any of the above conditions does not hold, then this means that
                // this is an illegal move and an error message is returned.
                cerr << "illegal move" << endl;
            }
            break;

        // same moving operation is done for each 6 cases. Only the rods differ.
        case 1:
            if(num_disc[2] == 0 && rod0[0] != 0){
                num_disc[2]++;
                rod2[num_disc[2] - 1] = rod0[num_disc[0] - 1];
                rod0[num_disc[0] - 1] = 0; num_disc[0]--;
                //cout << "Disc " << Get_Diameter(2,num_disc[2] - 1) <<
                //     " is moved from rod0 to rod2" << endl;
            }
            else if(rod0[num_disc[0] - 1] < rod2[num_disc[2] - 1] && num_disc[2] > 0 && num_disc[0] > 0){
                num_disc[2]++;
                rod2[num_disc[2] - 1] = rod0[num_disc[0] - 1];
                rod0[num_disc[0] - 1] = 0; num_disc[0]--;
                //cout << "Disc " << Get_Diameter(2,num_disc[2] - 1) <<
                //     " is moved from rod0 to rod2" << endl;
            }
            else{
                cerr << "illegal move" << endl;
            }
            break;
        case 2:
            if(num_disc[0] == 0 && rod1[0] != 0){
                num_disc[0]++;
                rod0[num_disc[0] - 1] = rod1[num_disc[1] - 1];
                rod1[num_disc[1] - 1] = 0; num_disc[1]--;
                //cout << "Disc " << Get_Diameter(0,num_disc[0] - 1) <<
                //     " is moved from rod1 to rod0" << endl;
            }
            else if(rod1[num_disc[1] - 1] < rod0[num_disc[0] - 1] && num_disc[1] > 0 && num_disc[0] > 0){
                num_disc[0]++;
                rod0[num_disc[0] - 1] = rod1[num_disc[1] - 1];
                rod1[num_disc[1] - 1] = 0; num_disc[1]--;
                //cout << "Disc " << Get_Diameter(0,num_disc[0] - 1) <<
                //     " is moved from rod1 to rod0" << endl;
            }
            else{
                cerr << "illegal move" << endl;
            }
            break;
        case 3:
            if(num_disc[2] == 0 && rod1[0] != 0){
                num_disc[2]++;
                rod2[num_disc[2] - 1] = rod1[num_disc[1] - 1];
                rod1[num_disc[1] - 1] = 0; num_disc[1]--;
                //cout << "Disc " << Get_Diameter(2,num_disc[2] - 1) <<
                //     " is moved from rod1 to rod2" << endl;
            }
            else if(rod1[num_disc[1] - 1] < rod2[num_disc[2] - 1] && num_disc[1] > 0 && num_disc[2] > 0){
                num_disc[2]++;
                rod2[num_disc[2] - 1] = rod1[num_disc[1] - 1];
                rod1[num_disc[1] - 1] = 0; num_disc[1]--;
                //cout << "Disc " << Get_Diameter(2,num_disc[2] - 1) <<
                //     " is moved from rod1 to rod2" << endl;
            }
            else{
                cerr << "illegal move" << endl;
            }
            break;
        case 4:
            if(num_disc[0] == 0 && rod2[0] != 0){
                num_disc[0]++;
                rod0[num_disc[0] - 1] = rod2[num_disc[2] - 1];
                rod2[num_disc[2] - 1] = 0; num_disc[2]--;
                //cout << "Disc " << Get_Diameter(0,num_disc[0] - 1) <<
                //     " is moved from rod2 to rod0" << endl;
            }
            else if(rod2[num_disc[2] - 1] < rod0[num_disc[0] - 1] && num_disc[2] > 0 && num_disc[0] > 0){
                num_disc[0]++;
                rod0[num_disc[0] - 1] = rod2[num_disc[2] - 1];
                rod2[num_disc[2] - 1] = 0; num_disc[2]--;
                //cout << "Disc " << Get_Diameter(0,num_disc[0] - 1) <<
                //     " is moved from rod2 to rod0" << endl;
            }
            else{
                cerr << "illegal move" << endl;
            }
            break;
        case 5:
            if(num_disc[1] == 0 && rod2[0] != 0){
                num_disc[1]++;
                rod1[num_disc[1] - 1] = rod2[num_disc[2] - 1];
                rod2[num_disc[2] - 1] = 0; num_disc[2]--;
                //cout << "Disc " << Get_Diameter(1,num_disc[1] - 1) <<
                //     " is moved from rod2 to rod1" << endl;
            }
            else if(rod2[num_disc[2] - 1] < rod1[num_disc[1] - 1] && num_disc[2] > 0 && num_disc[1] > 0){
                num_disc[1]++;
                rod1[num_disc[1] - 1] = rod2[num_disc[2] - 1];
                rod2[num_disc[2] - 1] = 0; num_disc[2]--;
                //cout << "Disc " << Get_Diameter(1,num_disc[1] - 1) <<
                //     " is moved from rod2 to rod1" << endl;
            }
            else{
                cerr << "illegal move" << endl;
            }
            break;
    }

}
