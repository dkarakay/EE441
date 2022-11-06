
#ifndef PRINT_H_INCLUDED
#define PRINT_H_INCLUDED

using namespace std;


void print_backwards(char const * str)
{
    if(*str) // If the character of the string is available
    {
        print_backwards(str+1); // Recursively
        cout<<*str;
    }

}


#endif // PRINT_H_INCLUDED

