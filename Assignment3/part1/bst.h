
class BST_Node
{

public:
    BST_Node();
    BST_Node(Matrix A, long detA);
    BST_Node* left;
    BST_Node* right;
    BST_Node* root;
    Matrix key;
    long value;

    bool key_exists(Matrix A);
    long search(Matrix A);
    void insert(Matrix A, long detA);

    BST_Node* _insert(BST_Node* root,Matrix A, long detA);
    void print();

};



BST_Node::BST_Node()
{
    key = Matrix();
    value = 0;
    left  = nullptr;
    right = nullptr;
    root = this;

}


void BST_Node::insert(Matrix A, long detA)
{
    root = _insert(this,A,detA);
}


BST_Node* BST_Node::_insert(BST_Node* root, Matrix A,long detA)
{
    if(root == NULL)
    {
        return new BST_Node(A,detA);
    }
    else
    {
        BST_Node* cur;

        if(root->key.compareMatrices(A)==0)
        {
            return NULL;
        }

        else if(root->key.compareMatrices(A)==1)
        {
            cur = _insert(root->left, A ,detA);
            root->left = cur;
        }
        else if(root->key.compareMatrices(A)==2)
        {
            cur = _insert(root->right, A ,detA);
            root->right = cur;
        }
        return root;
    }
}

BST_Node::BST_Node(Matrix A,long detA)
{
    key = A;
    value = detA;
    left  = nullptr;
    right = nullptr;

}

/*void BST_Node::print(){
    if(!root) return;

    BST_Node *temp = root;
    while(root->left != NULL){
        cout << temp.value << endl;
        temp = temp

    }
}*/

