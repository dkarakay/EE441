#ifndef SET_H_INCLUDED
#define SET_H_INCLUDED



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





#endif // SET_H_INCLUDED

