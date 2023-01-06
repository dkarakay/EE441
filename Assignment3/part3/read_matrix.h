using namespace std;

// Read matrix using filename
Matrix read_matrix(string filename)
{
    cout <<endl<< "Matrix:" << endl << endl;
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
