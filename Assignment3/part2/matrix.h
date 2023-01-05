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
    bool operator==(Matrix& B);
    bool operator<(Matrix& B);

};

Matrix::Matrix()
{
    sizeN=0;
}

// Construct Matrix with n size
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

// Print Matrix
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

// Return element value based on row and col
int Matrix::getElement(int row, int col)
{
    return data[row][col];
}

// Return size
int Matrix::getSize()
{
    return sizeN;
}

// Setting element based on row, col and val
void Matrix::setElement(int row, int col, int val)
{
    data[row][col] = val;
}

// Overload == operator
bool Matrix::operator==(Matrix& B)
{
    // Get size of defined Matrix
    int sizeA = getSize();

    // Get size of matrix to compare
    int sizeB = B.getSize();

    // If their sizes are not equal, return false
    if(sizeA != sizeB)
    {
        return false;
    }
    else
    {
        for(int i = 0; i<sizeA; i++)
        {
            for(int j = 0; j<sizeA; j++)
            {
                // If an element of defined matrix is not equal to element of B matrix
                if(getElement(i,j) != B.getElement(i,j))
                {
                    return false;
                }
            }
        }
    }
    return true;
}

// Overload Operator
bool Matrix::operator<(Matrix& B)
{
    // Get size of defined Matrix
    int sizeA = getSize();

    // Get size of matrix to compare
    int sizeB = B.getSize();

    // If sizeA < size B, we reach our goal
    if(sizeA < sizeB)
    {
        return true;
    }

    // If size A > size B, we should return false
    else if(sizeA > sizeB)
    {
        return false;
    }

    // Check every elements
    else
    {
        for(int i = 0; i<sizeA; i++)
        {
            for(int j = 0; j<sizeA; j++)
            {
                // If an element of defined matrix is greater than element of B matrix
                if(getElement(i,j) > B.getElement(i,j))
                {
                    return false;
                }

                // If an element of defined matrix is less than element of B matrix
                else if(getElement(i,j) < B.getElement(i,j))
                {
                    return true;
                }
            }
        }
    }
    return false;
}




