#include <iostream>
#include <math.h>
#include <fstream>
#include <string>

#include "matrix.h"
#include "read_matrix.h"
#include "ht.h"
#include "bst.h"
#include "det_ht.h"
#include "det_bst.h"

using namespace std;


int main()
{


    HashTable* ht = new HashTable();
    for(int i=0; i<5; i++)
    {
        string filename = "matrices/15/" + to_string(i) + ".txt";
        Matrix m = read_matrix(filename);

        cout << endl << "Using Hash Table"<<endl;
        cout <<"Determinant: " <<determinant_ht(m,ht) << endl;

    }

    float size = sizeof(HT_Item) * ht->count;
    size /= 1048776;
    cout << endl;
    cout << "Total sizeof(HT_Item): " <<size << " MB"<< endl;
    cout << "Average sizeof(HT_Item): " << size/5  << " MB"<< endl;



    /*
        BinarySearchTree* bstree = new BinarySearchTree();
        for(int i=0; i<5; i++)
        {
            string filename = "matrices/15/" + to_string(i) + ".txt";
            Matrix m = read_matrix(filename);

            cout << endl << "Using Binary Search Tree"<<endl;
            cout <<"Determinant: " <<determinant_bst(m,bstree) << endl;

        }

        float size = sizeof(BST_Node) * bstree->count;
        size /= 1048776;
        cout << endl;
        cout << "Total sizeof(HT_Item): " <<size << " MB"<< endl;
        cout << "Average sizeof(HT_Item): " << size/5  << " MB"<< endl;
    */

    /*

    // Create new HashTable*
    HashTable* ht = new HashTable();


    cout << endl << "Using Hash Table"<<endl;
    cout <<"Determinant: " <<determinant_ht(m,ht) << endl;
    cout <<"sizeof(HT_Item): "<< ht->count << endl;


    // Create new BinarySearchTree*
    BinarySearchTree* bstree = new BinarySearchTree();

    cout << endl << "Using Binary Search Tree"<<endl;
    cout <<"Determinant: " <<determinant_bst(m,bstree) << endl;
    cout <<"sizeof(BST_Node): "<< bst->count << endl;

    */
    return 0;
}
