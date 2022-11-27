#include <iostream>
#include "Hanoi.h"

using namespace std;

// Recursive function which solves the game
void solver_algorithm(Hanoi &game, int n, int from_rod, int to_rod,
                  int aux_rod)
{

    // n is decremented at each step. When n is non-zero, the solver_algorithm
    // function is called within itself which makes it a recursive function.
    if (n == 0) {
        return;
    }
    // When n = 1, two solver_algorithm functions return and move function is called once.
    // When n = 2, two solver_algorithm functions does not return right away, the functions are called
    // again. And, the move function is called twice for each solver_algorithm function.
    // When n = 3, again two solver_algorithm functions does not return right away, they are called again,
    // then again, resulting in calling the move function four times in total. Hence, a sequence of 2^n
    // can be observed.
    else{
        solver_algorithm(game,n - 1, from_rod, aux_rod, to_rod);
        game.move(from_rod,to_rod);
        solver_algorithm(game,n - 1, aux_rod, to_rod, from_rod);
    }
}

// Solve function itself is not recursive. However, it contains the solver_algorithm function
// which is recursive. After the function returns, the game is solved.
void solve(Hanoi &game) {

    solver_algorithm(game,game.disc_quantity,0,2,1);

    cout << "game is solved" << endl;

}
