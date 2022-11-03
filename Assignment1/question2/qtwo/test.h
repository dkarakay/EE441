#ifndef SET_H_INCLUDED
#define SET_H_INCLUDED


class Hanoi
{
private:
    int discNumber=0;
public:
    int posOfRods[3];
    int rod1[20];
    int rod2[20];
    int rod3[20];
    Hanoi (int n);
    void move(int from, int to);
    void printRods();
};

class Disc
{
public:
    int diameter=0;
    Disc(int d);
};


#endif // SET_H_INCLUDED

