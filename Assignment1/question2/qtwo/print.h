
#ifndef PRINT_H_INCLUDED
#define PRINT_H_INCLUDED

using namespace std;


void print_backwards(char const * str)
{
    if(*str) // If the character of the string is available
    {
        print_backwards(str+1); // Recursively
        cout<<*str<<endl;
    }

}

int nth_prime(int n)
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





#endif // PRINT_H_INCLUDED
