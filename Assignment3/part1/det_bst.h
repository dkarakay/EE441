
// Find determinant
long determinant(Matrix M, BinarySearchTree* bstree)
{
    long result = 0;

    // If BinarySearchTree contains the matrix
    if(bstree->key_exists(M))
    {
        // Return the existing determinant
        return bstree->search(M);
    }

    // Recursive function
    else
    {
        // If Matrix is 2x2 calculate determinant directly
        if(M.getSize() == 2)
        {
            long det = M.getElement(0,0) * M.getElement(1,1);
            det -= M.getElement(0,1) * M.getElement(1,0);

            return det;
        }

        // Check if matrix has larger than 2x2
        for(int j=0; j<M.getSize(); j++)
        {
            // Get sub matrix
            Matrix sub = sub_matrix(M,0,j);

            // Calculate the determinant of sub_matrix
            long sub_det = determinant(sub,bstree);

            // Insert the determinant and the matrix to the BinarySearchTree
            bstree->insert(bstree->getRoot(),sub,sub_det);

            // Calculate cofactor
            long cofactor = pow(-1,0+j) * M.getElement(0,j) * sub_det;

            // Add cofactor to the result value
            result += cofactor;
        }
    }

    // Return result determinant
    return result;
}
