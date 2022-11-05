#ifndef SET_H_INCLUDED
#define SET_H_INCLUDED

using namespace std;


class Disc
{
private:
    int diameter=0;
public:
    Disc(int d);
    int getData();
};

class Hanoi
{
public:
    int discNumber=0;
    int moveCount=0;
    int lengthOfRods[3];
    Disc* rod0[20];
    Disc* rod1[20];
    Disc* rod2[20];
    int allRods[3][20];
    Hanoi (int n);
    void move(int from, int to);
    void print_rods();
    void copyingArrayFromAllRods(bool c);

};



void solve_hanoi_by_recursion(Hanoi &game,int numberOfDisc, int fromR, int toR,
                              int remainingR)
{
    if (numberOfDisc == 0)
    {
        cout << "Move count: " << game.moveCount << endl;

        return;
    }
    solve_hanoi_by_recursion(game,numberOfDisc - 1, fromR, remainingR, toR);
    game.move(fromR,toR);
    solve_hanoi_by_recursion(game,numberOfDisc - 1, remainingR, toR, fromR);
}

void solve_hanoi(Hanoi& game)
{
    solve_hanoi_by_recursion(game, game.discNumber,0,2,1);
}



#endif // SET_H_INCLUDED

