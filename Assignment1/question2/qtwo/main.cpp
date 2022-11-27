#include <iostream>
#include "print.h"
#include "hanoi.h"
#include "nth_prime.h"
using namespace std;

int main()
{

    Hanoi h = Hanoi(8);
    h.print_rods();
    solve_hanoi(h);
    cout<<endl;

    cout << "EE441 is full of fun" << endl;
    print_backwards("EE441 is full of fun");
    cout<<endl;

    cout<<"25th prime number: "<<nth_prime(25)<<endl;
    cout<<"75th prime number: "<<nth_prime(75)<<endl;
    cout<<"5th prime number:"<<nth_prime(5)<<endl;

    return 0;
}


