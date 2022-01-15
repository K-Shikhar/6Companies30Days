class Solution
{
    public:
    //Function to connect nodes at same level.
    void connect(Node *root)
    {
       queue<Node*> q;
       
       q.push(root);
       while(!q.empty())
       {
           int n=q.size();
           vector<Node*> v;
           while(n--)
           {
               Node* temp=q.front();
               q.pop();
               v.push_back(temp);
               if(temp->left)
               {
                  q.push(temp->left);
               }
               if(temp->right)
               {
                   q.push(temp->right);
               }
           }
           if(v.size()==1)
           {
               v[0]->nextRight=NULL;
           }
           for(int i=1;i<v.size();i++)
           {
               v[i-1]->nextRight=v[i];
           }
           v[v.size()-1]->nextRight=NULL;
       }
    }    
      
};