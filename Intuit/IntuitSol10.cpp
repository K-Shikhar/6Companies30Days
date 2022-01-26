void bfs(vector<vector<int>>& g,vector<vector<int>> &vis,int i,int n)
    {
        queue<int> q;
        q.push(i);
        
        while(!q.empty())
        {
            int k=q.front();
            q.pop();
            for(int j=0;j<n;j++)
            {
                if(vis[k][j]==1)
                {
                    continue;
                }
                
                if(vis[k][j]==0 && g[k][j]==1)
                {
                    q.push(j);
                    vis[k][j]=vis[j][k]=1;
                }
            }    
        }
    }
    int findCircleNum(vector<vector<int>>& g) 
    {
        int m=g.size();
        int n=g[0].size();
        
        vector<vector<int>> vis(m,vector<int>(n,0));
        int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(vis[i][j]==0 && g[i][j]==1)
                {
                    count++;
                    bfs(g,vis,i,n);            
                }
            }
        }
        return count;
    }