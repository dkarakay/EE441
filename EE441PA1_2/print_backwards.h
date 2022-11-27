#include <iostream>
using namespace std;

// *********  Print Backwards Function for Part 2.2  *********

// Recursive print_backwards
void print_backwards(char const * str) {
    // first return occurs at the end of the char input.
    if(*str == '\0'){
        return;
    }
    else {
        // str is incremented and fed into the print_backwards function
        print_backwards(str+1);
        // After the first return, the characters are printed one-by-one backwards
        cout<<*str;
    }
}

