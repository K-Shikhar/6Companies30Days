int ROW[4]={0,0,1,-1};
    int COL[4]={1,-1,0,0};
    
    int maxDistance(vector<vector<int>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({i,j});
                }
            }
        }
        int count=0;
        while(!q.empty())
        {
            pair<int,int> p=q.front();
              q.pop();
              for(int i=0;i<4;i++)
              {
                  int x=p.first+ROW[i];
                  int y=p.second+COL[i];
                  if(x>=0 && x<m && y>=0 && y<n && grid[x][y]==0)
                  {
                       q.push({x,y});
                       grid[x][y]=1+grid[p.first][p.second];
                  }
              }                    
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                count=max(grid[i][j],count);
            }
        }
        return count;
    }