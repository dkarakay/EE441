#ifndef SET_H_INCLUDED
#define SET_H_INCLUDED


template <int N> class Matrix{
private:
    double data[N][N];
public:
    Matrix ();
    void printT();

    int getElement(int r, int c);
    int setElement(int r, int c, int p);

    Matrix<N> addition(Matrix<N> m11, Matrix<N> m22);
    Matrix<N> subtraction(Matrix<N> m11, Matrix<N> m22);
    Matrix<N> multiplication(Matrix<N> m11, Matrix<N> m22);
    int matrixDeterminant(Matrix<N> m1, int nextSize);

    int const SIZE = N;
};


#endif // SET_H_INCLUDED
