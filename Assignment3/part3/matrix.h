using namespace std;

class Matrix
{
private:
    int data[20][20];
    int sizeN;
public:
    Matrix ();
    Matrix (int n);
    void print();

    int getSize();
    int getElement(int row, int col);
    void setElement(int row, int col, int val);
    int compareMatrices(Matrix B);

};

Matrix::Matrix()
{
    sizeN=0;
}

Matrix::Matrix(int n)
{
    sizeN = n;

    for(int i = 0; i< sizeN; i++)
    {
        for(int j = 0; j<sizeN; j++)
        {
            if(i == j) data[i][j] = 1;
            else data[i][j] = 0;
        }
    }

}

void Matrix::print()
{
    for(int i = 0; i< sizeN; i++)
    {
        for(int j = 0; j<sizeN; j++)
        {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

}


int Matrix::getElement(int row, int col)
{
    return data[row][col];
}

int Matrix::getSize()
{
    return sizeN;
}

void Matrix::setElement(int row, int col, int val)
{
    data[row][col] = val;
}

int Matrix::compareMatrices(Matrix B)
{
// Return 0 if Matrix A = Matrix B
// Return 1 if Matrix A > Matrix B
// Return 2 if Matrix A < Matrix B

    int sizeA = sizeN;
    int sizeB = B.getSize();

    if(sizeA > sizeB)
    {
        return 1;
    }
    else if(sizeA < sizeB)
    {
        return 2;
    }
    else
    {

        for(int i = 0; i<sizeA; i++)
        {
            for(int j = 0; j<sizeA; j++)
            {
                if(getElement(i,j) > B.getElement(i,j))
                {
                    return 1;
                }
                else if(getElement(i,j) < B.getElement(i,j))
                {
                    return 2;
                }
            }
        }
    }

    return 0;
}


