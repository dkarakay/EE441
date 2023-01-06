#include <iostream>
#include <math.h>
#include <fstream>
#include "matrix.h"
#include "ht.h"
#include "read_matrix.h"
#include "det_ht.h"

using namespace std;

int main()
{
    // Create new HashTable*
    HashTable* ht = new HashTable();

    Matrix m = read_matrix("matrices/15/4.txt");
    cout << endl << "Using Hash Table"<<endl;
    cout <<"Determinant: " <<determinant(m,ht) << endl;

    return 0;
}
