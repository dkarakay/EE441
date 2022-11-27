#include "Hanoi.h"
#include "Disc.h"

int step = 0;   // hold the number of actions taken
using namespace std;

void Hanoi_helper(int nth_disc, int init, int fin, int aux, Hanoi& game){
    if (nth_disc == 0){
        return;
    }
    step += 1;
    Hanoi_helper(nth_disc - 1, init, aux, fin, game);
    game.move(init, fin);
    Hanoi_helper(nth_disc - 1, aux, fin, init, game);
}

void solve_hanoi(Hanoi& game){
    // set init, aux, and fin by set_aux_fin function inside the Hanoi constructor
    cout << game.get_num_of_discs() << endl;
    cout << "FDSFSDFSD" << endl;
    Hanoi_helper(game.get_num_of_discs(), game.init, game.fin, game.aux, game);
    cout << "finito" << endl;
}
