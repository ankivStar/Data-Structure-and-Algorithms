void levelOrderTraversal(BinaryTreeNode<int> *root){
    if (root == NULL) return;

    queue<BinaryTreeNode<int> *>q;
    q.push(root);
    q.push(NULL);

    while (q.size() != 0){
        BinaryTreeNode<int> *front = q.front();
        q.pop();

        if (front != NULL){
            cout << front->data << " ";
            if(front->left != NULL) q.push(front->left);
            if(front->right != NULL) q.push(front->right);
        }
        if(front == NULL){
            if (q.empty()) break;
            cout << endl;
            q.push(NULL);
        } 
    }    
}