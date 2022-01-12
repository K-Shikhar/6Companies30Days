class Solution
{
    public:
    
    vector<int> v;
    
    void serialize1(Node* root)
    {
        if(root==NULL)
        {
            return;
        }
        serialize1(root->left);
        v.push_back(root->data);
        serialize1(root->right);
        return;
    }
    vector<int> serialize(Node *root) 
    {
        serialize1(root);
        return v;
    }
    
    //Function to deserialize a list and construct the tree.
    int index=0;
    Node * deSerialize(vector<int> &A)
    {
        struct Node* NewNode = new Node(-1);
        Node* temp = NewNode;
       
       for(int i=0;i<A.size();i++)
       {
           temp->right = new Node(A[i]);
           temp = temp->right;
       }
       return NewNode->right;
    }

};