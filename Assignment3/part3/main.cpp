#include <iostream>
#include <math.h>
#include <fstream>
#include "matrix.h"
#include "ht.h"

using namespace std;


// Read matrix using filename
Matrix read_matrix(string filename)
{

    string line;
    ifstream input_file;

    // Open file
    input_file.open (filename);

    // Determine the size of dimension using a function
    int dim = 0;
    while(getline(input_file, line))
    {
        // Check every valid line
        if (line.length() != 0 && line[0] != NULL)
        {
            cout << line<<endl;
            dim+=1;
        }
    }
    // Close input file
    input_file.close();

    // Open input file again and fill the new Matrix
    input_file.open (filename);

    // Create new matrix
    Matrix m = Matrix(dim);

    int i=0,j=0;
    while(getline(input_file, line,' '))
    {
        if (line.length() != 0)
        {
            // Convert string to number
            int num = stoi(line);
            // Setting new element of matrix
            m.setElement(i,j,num);

            // Check if we reach to the end of the row
            if(j == dim-1)
            {
                j=0;
                i++;
            }
            else
            {
                j++;
            }
        }

    }
    // Return new matrix
    return m;
}

// Creating a sub matrix from original
Matrix sub_matrix(Matrix orig, int row, int col)
{
    // Create a sub matrix with size n-1
    Matrix t = Matrix(orig.getSize()-1);


    // Skip row 0
    for(int i=1; i<orig.getSize(); i++)
    {
        int p = 0;
        // Traverse all items on specific row
        for(int j=0; j<orig.getSize(); j++)
        {
            // If selected column is not equal to index for row
            if(j!=col)
            {
                // Get original element using i,j and put it on new Matrix T using i-1,p
                t.setElement(i-1,p,orig.getElement(i,j));

                // Increment p, p is used to track the position of new matrix
                p++;
            }
        }
    }


    return t;
}


// Find determinant
int determinant(Matrix M, HashTable* ht)
{
    int result = 0;

    // If HashTable contains the matrix
    if(ht->key_exists(M))
    {
        // Return the existing determinant
        return ht->search(M);
    }

    // Recursive function
    else
    {
        // If Matrix is 2x2 calculate determinant directly
        if(M.getSize() == 2)
        {
            int det = M.getElement(0,0) * M.getElement(1,1);
            det -= M.getElement(0,1) * M.getElement(1,0);

            return det;
        }

        // Check if matrix has larger than 2x2
        for(int j=0; j<M.getSize(); j++)
        {
            // Get sub matrix
            Matrix sub = sub_matrix(M,0,j);

            // Calculate the determinant of sub_matrix
            int sub_det = determinant(sub,ht);

            // Insert the determinant and the matrix to the HashTable
            ht->insert(sub,sub_det);

            // Calculate cofactor
            int cofactor = pow(-1,0+j) * M.getElement(0,j) * sub_det;

            // Add cofactor to the result value
            result += cofactor;
        }
    }

    // Return result determinant
    return result;
}



int main()
{
    // Create new HashTable*
    HashTable* ht = new HashTable();

    Matrix m = read_matrix("matrices/15/0.txt");
    m.print();
    cout << determinant(m,ht) << endl;

    return 0;
}
