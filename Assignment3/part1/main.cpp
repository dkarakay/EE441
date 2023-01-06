#include <iostream>
#include <math.h>
#include <fstream>
#include "matrix.h"
#include "bst.h"
#include "read_matrix.h"
#include "det_bst.h"

using namespace std;


int main()
{
    // Create new BinarySearchTree*
    BinarySearchTree* bstree = new BinarySearchTree();

    Matrix m = read_matrix("matrices/15/4.txt");
    cout << endl << "Using Binary Search Tree"<<endl;
    cout <<"Determinant: " <<determinant(m,bstree) << endl;
    cout <<"sizeof(BST_Node): "<< bstree->count << endl;

    return 0;
}
