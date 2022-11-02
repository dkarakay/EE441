#ifndef SET_H_INCLUDED
#define SET_H_INCLUDED


template <int N> class Matrix{
private:
    double data[N][N];
public:
    Matrix ();
    void printT();
    //void addition(Matrix<N> m11, Matrix<N> m22);
    int getElement(int r, int c);
    int setElement(int r, int c, int p);
    int const SIZE = N;
};


#endif // SET_H_INCLUDED
