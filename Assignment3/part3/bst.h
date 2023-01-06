
class BST_Node
{
public:
    BST_Node* left;
    BST_Node* right;
    Matrix key;
    long value;
};



class BinarySearchTree
{
private:
    BST_Node* root;
public:
    int count=0;
    BinarySearchTree();
    BinarySearchTree(Matrix A, long detA);
    BST_Node* getRoot();
    bool key_exists(Matrix A);
    long search(Matrix A);
    BST_Node* insert(BST_Node* temp_root,Matrix A, long detA);
    void inorderPrint(BST_Node* start_root);
};


// Constructor
BinarySearchTree::BinarySearchTree()
{
    root = nullptr;

}

// Copy Constructor for Matrix A and long detA
BinarySearchTree::BinarySearchTree(Matrix A, long detA)
{
    root = new BST_Node();
    root->left  = nullptr;
    root->right = nullptr;
    root->key   = A;
    root->value = detA;
}

// Get Root node for insert and print functions
BST_Node* BinarySearchTree::getRoot()
{
    return root;
}

// Check if Matrix A exists in the tree
bool BinarySearchTree::key_exists(Matrix A)
{
    // If root is null, return false
    if(root == nullptr)
    {
        return false;
    }

    // If Matrix A is the key for root
    else if(root->key == A)
    {
        return true;
    }

    else
    {
        // Create temp_root node
        BST_Node* temp_root = root;

        // Check if root->value is null
        while(root->value != NULL)
        {
            // If temp_root is nullptr, then return false
            if(temp_root==nullptr)
            {
                return false;
            }

            // If we find the same key in tree
            else if(temp_root->key==A)
            {
                return true;
            }

            // If we look for a key that is greater than temp_root's key, go right
            else if(temp_root->key < A)
            {
                temp_root = temp_root->right;
            }

            // If we look for a key that is less than temp_root's key, go left
            else
            {
                temp_root = temp_root->left;

            }
        }

    }
    return false;
}

// Search for value
long BinarySearchTree::search(Matrix A)
{
    // If root is nullptr -> error
    if(root == nullptr)
    {
        return NULL;
    }

    // If Matrix A is the key for root
    else if(root->key == A)
    {
        return root->value;
    }

    else
    {
        // Create temp_root node
        BST_Node* temp_root = root;

        // Check if root->value is null
        while(root->value != NULL)
        {

            // If temp_root is nullptr -> error
            if(temp_root==nullptr)
            {
                return NULL;
            }

            // If we find the same key in tree
            else if(temp_root->key==A)
            {
                return temp_root->value;
            }

            // If we look for a key that is greater than temp_root's key, go right
            else if((temp_root->key < A))
            {
                temp_root = temp_root->right;
            }

            // If we look for a key that is less than temp_root's key, go left
            else
            {
                temp_root = temp_root->left;

            }
        }

    }
    return NULL;
}

// Insert to BinarySearchTree
BST_Node* BinarySearchTree::insert(BST_Node* temp_root, Matrix A, long detA)
{

    if(key_exists(A)){
        return NULL;
    }

    else {

        // If temp_root is null, create new node
        if(temp_root == nullptr)
        {
            temp_root = new BST_Node();
            temp_root->left  = nullptr;
            temp_root->right = nullptr;
            temp_root->key   = A;
            temp_root->value = detA;

            // Increment number of BST_Node objects
            count +=1;

            // Set root as new node
            root = temp_root;
            return temp_root;
        }
        else
        {
            BST_Node* track;

            // If we look for a key that is greater than temp_root's key, go right
            if(temp_root->key < A)
            {
                // Go to right recursively
                track = insert(temp_root->right, A, detA);
                temp_root->right = track;
            }

            // If we look for a key that is less than temp_root's key, go left
            else
            {
                // Go to left recursively
                track = insert(temp_root->left, A, detA);
                temp_root->left = track;
            }

            // Set root as new node
            root = temp_root;
            return temp_root;
        }
    }



}

// Print Binary Search Tree inorder
void BinarySearchTree::inorderPrint(BST_Node* start_root)
{
    if(start_root==nullptr)
    {
        return;
    }

    // L - N - R
    // Prints in ascending order
    inorderPrint(start_root->left);

    start_root->key.print();
    cout <<endl<< start_root->value << " " << endl;;

    inorderPrint(start_root->right);
}

