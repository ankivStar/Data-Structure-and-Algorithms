
void traverse(BinaryTreeNode<int> *root){
    if (!root) return;
    
    queue<BinaryTreeNode<int> *> printingNodes;
    printingNodes.push(root);

    while (printingNodes.size() != 0){
        BinaryTreeNode<int> *front = printingNodes.front();
        printingNodes.pop();

        cout << front->data << " : ";

        if(front->left != NULL){
            cout << "L" << front->left->data;
            printingNodes.push(front->left); 
        }

        if(front->right != NULL){
            cout << "R" << front->right->data;
            printingNodes.push(front->right); 
        }
        cout << endl;
    }
}