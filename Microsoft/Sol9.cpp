int findcount(Node* root,int X,int &count)
{
    if(root==NULL)
    {
        return 0;
    }
    int l=findcount(root->left,X,count);
    int r=findcount(root->right,X,count);
    
    if(X==(l+r+root->data))
    {
        count++;
    }
    return l+r+root->data;
}
int countSubtreesWithSumX(Node* root, int X)
{
    int count=0;
    findcount(root,X,count);
    return count;
}