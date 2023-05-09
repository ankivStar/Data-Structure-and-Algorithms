class BST{
    BinaryTreeNode<int> *root;

    public :

    BST(){
        root = nullptr;
    }

    ~BST(){
        delete root;
    }

    private :
    BinaryTreeNode<int>* deleteData(int data, BinaryTreeNode<int>* node){
        if (node == nullptr){
            return nullptr;
        }

        if (data > node->data){
           node->right = deleteData(data, node->right);
           return node;
        }else if (data < node->data){
            node->left = deleteData(data, node->left);
            return node;
        }else {
            if (node->left == nullptr and node->right == nullptr){
                delete node;
                return nullptr;
            }else if (node->left == nullptr){
                BinaryTreeNode<int> * temp = node->right;
                node->right = nullptr;
                delete node;
                return temp;
            }else if (node->right == nullptr){
                BinaryTreeNode<int>* temp = node->left;
                node->left = nullptr;
                delete node;
                return temp;
            }else{
                BinaryTreeNode<int>* minNode = node->right;
                while (minNode->left != nullptr){
                    minNode = minNode->left;
                }
                int rightMin = minNode->data;
                root->data = rightMin;
                node->right = deleteData(rightMin, node->right);
                return node;
            }
        }
    }
    public :
    void deleteData(int data){
        root = deleteData(data, root);
    }

    private :
    BinaryTreeNode<int>* insert(int data, BinaryTreeNode<int>* node){
        if (node == nullptr){
            BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }

        if (data < node->data){
            node->left = insert(data, node->left);
        }else{
            node->right = insert(data, node->right);
        }
        return node;
    }
    public :
    void insert(int data){
        this->root = insert(data, this->root);
    }

    private :
    bool hasData(int data, BinaryTreeNode<int>* node){
        if (node == nullptr){
            return false;
        }

        if (node->data == data){
            return true;
        }else if (data < node->data){
            return hasData(data, node->left);
        }else{
            return hasData(data, node->right);
        }
    }

    public :
    bool hasData(int data){
        return hasData(data, root);
    }

    private : 
    void printTree(BinaryTreeNode<int>* root){
        if (root == nullptr){
            return;
        }

        cout << root->data << ":";
        if (root->left != nullptr){
            cout << "L" << root->left->data;
        }

        if (root->right != nullptr){
            cout << "R" << root->right->data;
        }
        cout << endl;
        printTree(root->left);
        printTree(root->right);
    }

    public :
    void printTree(){
        printTree(root);
    }
};