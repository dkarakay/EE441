
// Find determinant
long determinant_ht(Matrix M, HashTable* ht)
{
    long result = 0;

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
            long sub_det = determinant_ht(sub,ht);

            // Insert the determinant and the matrix to the HashTable
            ht->insert(sub,sub_det);

            // Calculate cofactor
            long cofactor = pow(-1,0+j) * M.getElement(0,j) * sub_det;

            // Add cofactor to the result value
            result += cofactor;
        }
    }

    // Return result determinant
    return result;
}
