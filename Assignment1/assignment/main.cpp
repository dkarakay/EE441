#include <iostream>
#include "set.h"
#include <math.h>
using namespace std;


template <int N>
Matrix<N> :: Matrix ()
{
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            if(i == j)
            {
                data[i][j] = 1;
            }
            else
            {
                data[i][j] = 0;

            }
        }
    }

}

template <int N>
int Matrix<N>:: getElement(int i, int j)
{
    if(i<0 || i>=SIZE)
    {
        return -1;
    }

    if(j<0 || j>=SIZE)
    {
        return -1;
    }

    return data[i][j];
}

template <int N>
int Matrix<N>:: setElement(int i, int j, int input)
{
    if(i<0 || i>=SIZE)
    {
        return -1;
    }

    if(j<0 || j>=SIZE)
    {
        return -1;
    }

    data[i][j] = input;
}

template <int N>
void Matrix<N>:: printT()
{
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            cout << data[i][j];
        }
        cout<<endl;
    }
}
template <int N>
Matrix<N> matrixAddition(Matrix<N> m1, Matrix<N> m2)
{
    Matrix<N> newMatrix;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            int m1Data = m1.getElement(i,j);
            int m2Data = m2.getElement(i,j);
            newMatrix.setElement(i,j,m1Data+m2Data);
        }
    }
    return newMatrix;
}

template <int N>
Matrix<N> matrixSubtraction(Matrix<N> m1, Matrix<N> m2)
{
    Matrix<N> newMatrix;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            int m1Data = m1.getElement(i,j);
            int m2Data = m2.getElement(i,j);
            newMatrix.setElement(i,j,m1Data-m2Data);
        }
    }
    return newMatrix;
}

template <int N>
Matrix<N> matrixMultiplication(Matrix<N> m1, Matrix<N> m2)
{
    Matrix<N> newMatrix;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            newMatrix.setElement(i,j,0);
            for(int k = 0; k < N; k++)
            {
                int m1Data = m1.getElement(i,k);
                int m2Data = m2.getElement(k,j);
                int currentData = newMatrix.getElement(i,j);
                currentData += m1Data*m2Data;
                newMatrix.setElement(i,j,currentData);



            }
        }
    }
    return newMatrix;
}


template <int N>
int matrixDeterminant(Matrix<N> m1, int nextSize)
{
    Matrix<N> mSub;
    int determinant = 0;
    if(nextSize==2)
    {
        int zz = m1.getElement(0,0);
        int zo = m1.getElement(0,1);
        int oz = m1.getElement(1,0);
        int oo = m1.getElement(1,1);

        return zz*oo - zo*oz;
    }
    else
    {

        for (int x = 0; x < nextSize; x++)
        {
            int posi = 0;
            for(int i = 1; i < nextSize; i++)
            {
                int posj = 0;
                for(int j = 0; j < nextSize; j++)
                {
                    if(j==x)
                    {
                        continue;
                    }

                    mSub.setElement(posi,posj,m1.getElement(i,j));
                    posj++;

                }
                posi++;
            }
            determinant = determinant + (pow(-1, x) * m1.getElement(0,x) * matrixDeterminant(mSub,nextSize-1));
        }


    }
    return determinant;
}

int main()
{
    Matrix<5> m1;
    cout<<"M1:"<<endl;
    m1.printT();
    cout<<endl;

    cout<< m1.getElement(0,1)<< endl;
    cout<< m1.getElement(0,0)<< endl;
    cout<< m1.setElement(0,0,1)<< endl;
    m1.printT();
    cout<<endl;

    Matrix<5> m3 = matrixAddition(m1,m1);
    cout<<"Addition m1+m1"<<endl;
    m3.printT();
    cout<<endl;

    Matrix<5> m4 = matrixSubtraction(m1,m1);
    cout<<"Subtraction m1-m1"<<endl;
    m4.printT();
    cout<<endl;

    Matrix<3> m2;
    m2.setElement(0,0,2);
    m2.setElement(0,1,2);
    m2.setElement(0,2,2);
    m2.setElement(1,0,3);
    m2.setElement(1,1,3);
    m2.setElement(1,2,3);
    m2.setElement(2,0,4);
    m2.setElement(2,1,4);
    m2.setElement(2,2,4);


    Matrix<3> m22;
    m22.setElement(0,0,1);
    m22.setElement(0,1,1);
    m22.setElement(0,2,1);
    m22.setElement(1,0,5);
    m22.setElement(1,1,5);
    m22.setElement(1,2,5);
    m22.setElement(2,0,7);
    m22.setElement(2,1,7);
    m22.setElement(2,2,7);

    cout<<"M2:"<<endl;
    m2.printT();
    cout<<endl;

    cout<<"M22:"<<endl;
    m22.printT();
    cout<<endl;

    Matrix<3> m5 = matrixMultiplication(m2,m22);
    cout<<"Multiplication m2*m22"<<endl;
    m5.printT();

    cout<<endl;
    Matrix<3> m33;
    int det = matrixDeterminant(m33,m33.SIZE);
    m33.printT();
    cout<<"determinant of m33: "<<det<<endl;
    cout<<endl;


    int det2 = matrixDeterminant(m22,m22.SIZE);
    m22.printT();
    cout<<"determinant of m22: "<<det2<<endl;
    return 0;
}
