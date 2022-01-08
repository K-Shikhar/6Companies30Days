int minTime(Node* root, int target) 
    {
        queue<Node*> q;
        int time=0;
        map<Node*,Node*> m;
        q.push(root);
        Node* t;
        while(!q.empty())
        {
            Node* temp=q.front();
            q.pop();
            if(temp->data==target)
            {
                t=temp;
            }
            if(temp->left)
            {
                m[temp->left]=temp;
                q.push(temp->left);
            }
            if(temp->right)
            {
                m[temp->right]=temp;
                q.push(temp->right);
            }
        }
        
        queue<Node*> q2;
        
        q2.push(t);
        map<Node*,int> visited;
        visited[t]=1;
        while(!q2.empty())
        {
            int n=q2.size();
            int k=0;
            while(n--)
            {
                Node* temp=q2.front();
                q2.pop();
                if(m[temp] && !visited[m[temp]])
                {
                    q2.push(m[temp]);
                    visited[m[temp]]=1;
                    k++;
                }
                if(temp->left && !visited[temp->left])
                {
                    visited[temp->left]=1;
                    q2.push(temp->left);
                    k++;
                }
                if(temp->right && !visited[temp->right])
                {
                    visited[temp->right]=1;
                    q2.push(temp->right);
                    k++;
                }
            }
            if(k)
            time++;
        }
        
        return time;
    }