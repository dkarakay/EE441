#include <iostream>
#include <chrono>
#include "Hanoi.h"
#include "solve_hanoi.h"
#include "nth_prime.h"
#include "print_backwards.h"
using namespace std;





void benchmark(void (*func)(int))
{
    int const AMOUNT = 20;
    int const REPEAT = 10;
    double results[AMOUNT];
    for (int i = 0 ; i < AMOUNT ; ++i) {
        auto start = std::chrono::steady_clock::now();
        for (int j = 0 ; j < REPEAT ; ++j) {
            func(i+1);
        }
        auto finish = std::chrono::steady_clock::now();
        results[i] = std::chrono::duration_cast<std::chrono::duration<double>>(finish - start).count() / REPEAT;
    }

    std::cout << std::endl << std::endl;
    std::cout << "n\ttime (ns)\n";
    for (int i = 0 ; i < AMOUNT ; ++i) {
        std::cout << i+1 << '\t' << results[i] << '\n';
    }
    std::cout << std::endl;
}

void wrapper_solve_hanoi(int n)
{
    auto game = Hanoi(n);
    solve(game);
}

void wrapper_print_backwards(int n)
{
    char * str = new char[n+1];
    for (int i = 0 ; i < n ; ++i) {
        str[i] = 'a' + i;
    }
    str[n] = '\0';

    print_backwards(str);

    delete[] str;
}

void wrapper_nth_prime(int n)
{
    volatile int temp = nth_Prime(n);
}

int main()
{
    benchmark(wrapper_solve_hanoi);
    //benchmark(wrapper_print_backwards);
    //benchmark(wrapper_nth_prime);
}




/*
int main() {
    /*
    Discs Disc1;
    Discs Disc2(4);

    cout << "testing Get_Diameter()..." << endl;
    cout << "Disc 1 diameter: " << Disc1.Get_Diameter() << endl;
    Disc1.Set_Diameter(3);

    cout << "testing Set_Diameter()..." << endl;
    cout << "Disc 2 diameter: " << Disc2.Get_Diameter() << endl;
    cout << "Disc 1 diameter: " << Disc1.Get_Diameter() << endl;
    */
/*
    Hanoi han(20);


    for(int i = 0; i < han.disc_quantity; i++){
        cout << "Disc No:" << i + 1 << " has diameter " << han.Disc_Storage(i)<< endl;
    }
    /*
    //han.move(2,0);
    cout << "rod0[4]: " << han.Get_Diameter(0,4) << endl;
    cout << "rod1[0]: " << han.Get_Diameter(1,0) << endl;
    cout << "rod2[0]: " << han.Get_Diameter(2,0) << endl;
    han.move(0,1);
    cout << "rod0[4]: " << han.Get_Diameter(0,4) << endl;
    cout << "rod1[0]: " << han.Get_Diameter(1,0) << endl;
    cout << "rod2[0]: " << han.Get_Diameter(2,0) << endl;
    han.move(1,2);
    cout << "rod0[4]: " << han.Get_Diameter(0,4) << endl;
    cout << "rod1[0]: " << han.Get_Diameter(1,0) << endl;
    cout << "rod2[0]: " << han.Get_Diameter(2,0) << endl;
    han.move(2,1);
    cout << "rod0[4]: " << han.Get_Diameter(0,4) << endl;
    cout << "rod1[0]: " << han.Get_Diameter(1,0) << endl;
    cout << "rod2[0]: " << han.Get_Diameter(2,0) << endl;
    han.move(0,2);
    cout << "rod0[3]: " << han.Get_Diameter(0,3) << endl;
    cout << "rod1[0]: " << han.Get_Diameter(1,0) << endl;
    cout << "rod2[0]: " << han.Get_Diameter(2,0) << endl;
    han.move(1,2);
    cout << "rod0[2]: " << han.Get_Diameter(0,2) << endl;
    cout << "rod1[0]: " << han.Get_Diameter(1,0) << endl;
    cout << "rod2[0]: " << han.Get_Diameter(2,0) << endl;


    //han.move(0,2);
    //han.move(1,2);
    //han.move(2,2);
    */
    /*
    // Printing the message backwards for Part 2.2

    cout << "Printing the message backwards for Part 2.2... " << endl;

    char msg[] = "I had fun doing the Programming Assignment 1";
    cout <<"Original String: " << msg << endl;
    cout <<"Reversed String: ";print_backwards(msg);
    cout << endl;

    cout << "Checking if PrimeOrNot Function works or not" << endl;
    cout << "5: " << PrimeOrNot(5) << endl;
    cout << "6: " << PrimeOrNot(6) << endl;
    cout << "7: " << PrimeOrNot(7) << endl;
    cout << "11: " << PrimeOrNot(11) << endl;
    cout << "16: " << PrimeOrNot(16) << endl;
    cout << "131: " << PrimeOrNot(131) << endl;

    cout << "Obtaining the nth prime number via nth_Prime function..." << endl;
    cout << "5th prime number is " << nth_Prime(5) << endl;
    cout << "6th prime number is " << nth_Prime(6) << endl;
    cout << "12th prime number is " << nth_Prime(12) << endl;
    cout << "25th prime number is " << nth_Prime(25) << endl;
    */

    //han.move(0,1); han.move(0,2);
    //han.move(1,2); han.move(0,1);
    //han.move(2,1);

/*
    cout << "rod0[1]: " << han.Get_Diameter(0,1) << endl;
    cout << "rod1[1]: " << han.Get_Diameter(1,1) << endl;
    cout << "rod1[0]: " << han.Get_Diameter(1,0) << endl;
    cout << "rod2[0]: " << han.Get_Diameter(2,0) << endl;


    solve(han);

    cout << "rod0[1]: " << han.Get_Diameter(0,1) << endl;
    cout << "rod0[0]: " << han.Get_Diameter(0,0) << endl;
    cout << "rod1[1]: " << han.Get_Diameter(1,1) << endl;
    cout << "rod1[0]: " << han.Get_Diameter(1,0) << endl;

    cout << "*******************" << endl;
    cout << "rod2[19]: " << han.Get_Diameter(2,19) << endl;
    cout << "rod2[18]: " << han.Get_Diameter(2,18) << endl;
    cout << "rod2[17]: " << han.Get_Diameter(2,17) << endl;
    cout << "rod2[16]: " << han.Get_Diameter(2,16) << endl;
    cout << "rod2[15]: " << han.Get_Diameter(2,15) << endl;
    cout << "rod2[14]: " << han.Get_Diameter(2,14) << endl;
    cout << "rod2[13]: " << han.Get_Diameter(2,13) << endl;
    cout << "rod2[12]: " << han.Get_Diameter(2,12) << endl;
    cout << "rod2[11]: " << han.Get_Diameter(2,11) << endl;
    cout << "rod2[10]: " << han.Get_Diameter(2,10) << endl;
    cout << "rod2[9]: " << han.Get_Diameter(2,9) << endl;
    cout << "rod2[8]: " << han.Get_Diameter(2,8) << endl;
    cout << "rod2[7]: " << han.Get_Diameter(2,7) << endl;
    cout << "rod2[6]: " << han.Get_Diameter(2,6) << endl;
    cout << "rod2[5]: " << han.Get_Diameter(2,5) << endl;
    cout << "rod2[4]: " << han.Get_Diameter(2,4) << endl;
    cout << "rod2[3]: " << han.Get_Diameter(2,3) << endl;
    cout << "rod2[2]: " << han.Get_Diameter(2,2) << endl;
    cout << "rod2[1]: " << han.Get_Diameter(2,1) << endl;
    cout << "rod2[0]: " << han.Get_Diameter(2,0) << endl;




    return 0;
}
*/
