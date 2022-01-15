int ROW[8]={-1,1,0,0,-1,1,-1,1};
    int COL[8]={0,0,1,-1,-1,1,1,-1};
    bool isValid(vector<vector<int>>& grid,int x,int y,int m,int n)
    {
        if(x>=m || x<0 || y>=n || y<0 || grid[x][y]!=1)
        {
            return 0;
        }
        return 1;
    }
    int findmaxm(vector<vector<int>>& grid,int i,int j,int m,int n)
    {
        queue<pair<int,int>> q;
        q.push({i,j});
        int z=0;
        while(!q.empty())
        {
            pair<int,int> p=q.front();
            q.pop();
            for(int k=0;k<8;k++)
            {
                int x=p.first+ROW[k];
                int y=p.second+COL[k];
                if(!isValid(grid,x,y,m,n))
                {
                    continue;
                }
                q.push({x,y});
                grid[x][y]=0;
            }
            if(!q.empty())
            {
                z+=1;
            }
        }
        return z;
    }
    int findMaxArea(vector<vector<int>>& grid) 
    {   
         int m=grid.size();
         int n=grid[0].size();
         int maxm=1;
         for(int i=0;i<m;i++)
         {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    int p=findmaxm(grid,i,j,m,n);
                    maxm=max(maxm,p);    
                }
            }
         }
         return maxm;
    }