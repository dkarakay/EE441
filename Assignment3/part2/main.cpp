#include <iostream>
#include <math.h>
#include <sstream>
#include <fstream>
#include "matrix.h"
#include "ht.h"

using namespace std;



Matrix read_matrix(string filename)
{

    string line;
    ifstream input_file;
    input_file.open (filename);
    int dim = 0;
    while(getline(input_file, line))
    {
        if (line.length() != 0 && line[0] != NULL)
        {
            cout << line<<endl;
            dim+=1;
        }
    }
    input_file.close();


    input_file.open (filename);
    cout << dim << endl;

    Matrix m = Matrix(dim);
    int i=0,j=0;

    while(getline(input_file, line,' '))
    {
        if (line.length() != 0)
        {
            //cout << line << endl;
            int num = stoi(line);
            //cout<<"i:"<< i << " j:" << j << " num:" << num<<endl;
            m.setElement(i,j,num);

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
    return m;
}

Matrix sub_matrix(Matrix orig, int row, int col)
{
    Matrix t = Matrix(orig.getSize()-1);


    for(int i=1; i<orig.getSize(); i++)
    {
        int p = 0;
        for(int j=0; j<orig.getSize(); j++)
        {
            if(j!=col)
            {
                //cout<<orig.getElement(i,j)<<endl;
                //cout<<"i:"<< i-1 << " j:" << j << " p:" << p<<endl;
                t.setElement(i-1,p,orig.getElement(i,j));
                p++;
            }
        }
    }


    return t;
}


int determinant(Matrix M, HashTable* ht)
{
    int result = 0;
    if(ht->key_exists(M))
    {
        return ht->search(M);
    }
    else
    {

        if(M.getSize() == 2)
        {
            int det = M.getElement(0,0) * M.getElement(1,1);
            det -= M.getElement(0,1) * M.getElement(1,0);

            return det;
        }

        for(int j=0; j<M.getSize(); j++)
        {
            Matrix sub = sub_matrix(M,0,j);
            int sub_det = determinant(sub,ht);
            ht->insert(sub,sub_det);

            int cofactor = pow(-1,0+j) * M.getElement(0,j) * sub_det;
            result += cofactor;
        }
    }


    return result;
}



int main()
{
    HashTable* ht = new HashTable();

    Matrix m = read_matrix("0.txt");
    m.print();
    //m = Matrix(4);
    //ht.insert(m,90);
    //ht.print_table();
    cout << determinant(m,ht) << endl;

    /*
    Matrix m = Matrix(5);
    Matrix m2 = Matrix(5);
    m2.setElement(0,0,43);

    m.print();
    m2.print();


    HashTable ht = HashTable();
    cout <<ht.hash(m)<<endl;

    ht.insert(m,56);
    ht.print_table();

    ht.insert(m,56);
    ht.print_table();

    ht.insert(m2,44);
    ht.print_table();

    cout << ht.search(m) << endl;
    cout << ht.search(m2) << endl;
    */
    return 0;
}
