#ifndef HANOIT_H_INCLUDED
#define HANOIT_H_INCLUDED

//using namespace std;


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


Disc::Disc(int d)
{
    diameter = d;
}

int Disc::getData()
{
    return diameter;
}


Hanoi::Hanoi(int n)
{
    discNumber = n;

    //cout << discNumber << endl;

    for(int i=0; i<20; i++)
    {
        allRods[0][i] = 0;
        allRods[1][i] = 0;
        allRods[2][i] = 0;
        rod0[i] = new Disc(0);
        rod1[i] = new Disc(0);
        rod2[i] = new Disc(0);
    }


    for(int i=discNumber-1; i>=0; i--)
    {
        rod0[i] = new Disc(discNumber-i);
    }



    lengthOfRods[0] = discNumber;
    lengthOfRods[1] = 0;
    lengthOfRods[2] = 0;

    copyingArrayFromAllRods(false);

}

void Hanoi::copyingArrayFromAllRods(bool check)
{

    if(check == false)
    {
        for(int j = 0; j < lengthOfRods[0]; j++)
        {
            allRods[0][j] = (*rod0[j]).getData();
        }

        for(int j = 0; j < lengthOfRods[1]; j++)
        {
            allRods[1][j] = (*rod1[j]).getData();
        }

        for(int j = 0; j < lengthOfRods[2]; j++)
        {
            allRods[2][j] = (*rod2[j]).getData();
        }
    }
    else
    {
        for(int j = 0; j < 20; j++)
        {
            rod0[j] = new Disc(allRods[0][j]);
            rod1[j] = new Disc(allRods[1][j]);
            rod2[j] = new Disc(allRods[2][j]);

        }

    }
}


void Hanoi::print_rods()
{
    /*cout << "copy" << endl;

    for(int i = 19; i>=0; i--)
    {

        int rod0Val = allRods[0][i];
        int rod1Val = allRods[1][i];
        int rod2Val = allRods[2][i];

        if(rod0Val+rod1Val+rod2Val != 0)
        {
            cout << rod0Val << " - " << rod1Val << " - " << rod2Val << endl;
        }
    }
*/
   /* cout << "original" << endl;

    for(int i = 19; i>=0; i--)
    {


        int rod0Val = (*rod0[i]).getData();
        int rod1Val = (*rod1[i]).getData();
        int rod2Val = (*rod2[i]).getData();

        if(rod0Val+rod1Val+rod2Val != 0)
        {
            cout << rod0Val << " - " << rod1Val << " - " << rod2Val << endl;
        }
    }*/
}

void Hanoi::move(int from, int to)
{

    if(lengthOfRods[from] <= 0 || lengthOfRods[to] >= 20 )
    {
       // cout << "Empty or invalid index" << endl;
        return;
    }

    int fromDisc = 0;
    int toDisc = 0;


    int fromRodMaxIndex = lengthOfRods[from];
    int toRodMaxIndex = lengthOfRods[to];

    if(fromRodMaxIndex > 0)
    {
        fromRodMaxIndex -= 1;
    }
    if(toRodMaxIndex > 0)
    {
        toRodMaxIndex -= 0;
    }

    fromDisc = allRods[from][fromRodMaxIndex];
    toDisc = allRods[to][toRodMaxIndex];
    /*
        cout << from << "R->" << to << endl;
        cout << fromL << "L->" << toL << endl;
        cout << fromDisc << "Disc->" << toDisc << endl;
    */
    if(toDisc == 0 || (toDisc != 0 && fromDisc < toDisc))
    {
        allRods[from][fromRodMaxIndex] = 0;
        allRods[to][toRodMaxIndex] = fromDisc;
        lengthOfRods[from] -=1;
        lengthOfRods[to] +=1;

        //cout << "Disc " << fromDisc << " is moved from Rod " << from << " to Rod " << to <<endl;
    }
    else
    {
        //cout << "Invalid move" << endl;
        return;
    }

    copyingArrayFromAllRods(true);
    print_rods();
    moveCount +=1;

}




void solve_hanoi_by_recursion(Hanoi &game,int numberOfDisc, int fromR, int toR,
                              int remainingR)
{
    if (numberOfDisc == 0)
    {
        //cout << "Move count: " << game.moveCount << endl;

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



#endif // SET_HANOIT_INCLUDED

