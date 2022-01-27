 int findsum(Node* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int k=root->data;
        
        root->data=findsum(root->left)+findsum(root->right);
        
        return k+root->data;
    }
    void toSumTree(Node *node)
    {
        findsum(node);
    }