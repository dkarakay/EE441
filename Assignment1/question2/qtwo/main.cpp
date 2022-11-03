#include <iostream>
#include "test.h"
using namespace std;

Disc::Disc(int d)
{
    diameter = d;
}

Hanoi::Hanoi(int n)
{
    discNumber = n;

    for(int i=0; i<discNumber; i++)
    {

    }

    for(int i=0; i<20; i++)
    {
        rod1[i] = 0;
        rod2[i] = 0;
        rod3[i] = 0;
    }


    posOfRods[0] = 0;
    posOfRods[1] = 0;
    posOfRods[2] = 0;

    rod1[0] = 5;
    rod1[1] = 4;
    rod1[2] = 3;
    rod1[3] = 2;
    rod1[4] = 1;
    posOfRods[0] = 5;


}

void Hanoi::printRods()
{
    cout << posOfRods[0] << endl;
    for(int i = 0; i<2; i++)
    {
        for(int j=0; j<posOfRods[0]; j++)
        {
            cout << rod1[j] << endl;
        }
    }
}

void Hanoi::move(int from, int to)
{

    cout<<"test"<<endl;
    if(posOfRods[from] <= 0 || posOfRods[to] >= 20 )
    {
        cout << "Empty or invalid index" << endl;
        return;
    }

    int fromDisc = 0;
    int toDisc = 0;

    if (from == 0 && to == 1)
    {
        fromDisc = rod1[posOfRods[0]];
        toDisc = rod2[posOfRods[1]];

        if((toDisc != 0 && fromDisc < toDisc) || toDisc == 0)
        {
            rod1[posOfRods[0]] = 0;
            rod2[posOfRods[1]] = fromDisc;
            cout << "Disc x is moved from Rod 0 to Rod 1"<<endl;
            cout << posOfRods[0] << endl;
            posOfRods[from] -=1;
            cout << posOfRods[0] << endl;

            posOfRods[to] +=1;

            cout << "Disc x is moved from Rod 0 to Rod 1"<<endl;


        }
    }

}

void print_backwards(char const * str)
{
    if(*str) // If the character of the string is available
    {
        print_backwards(str+1); // Recursively
        cout<<*str<<endl;
    }

}


int n_th_prime(int n)
{
    int x = 1; // Number that we are checking if it is prime
    int i = 2; // Index
    int count = 0; // Count of prime numbers that we found

    // If count is less than n
    while(count < n)
    {
        x +=1; // Increment x by 1
        for(i = 2; i<x; i++) // traverse numbers till x s.t. finding prime numbers will be easy
        {
            if(x%i == 0)
            {
                break;
            }
        }
        if(i == x) // If x and i are equal, we can say that x is a prime number
        {
            count +=1;
        }
    }
    return x;
}

int main()
{

    Disc(4);
    Hanoi h = Hanoi(5);
    h.printRods();
    h.move(0,1);
    h.printRods();


    print_backwards("EE441 is fun");
    cout<<endl;
    cout<<"n_th_prime(25): "<<n_th_prime(25)<<endl;
    return 0;
}
