class Solution {
public:
    int ROW[4]={-1,0,0,+1};
    int COL[4]={0,-1,1,0};
    bool isValid(int x,int y,int m,int n,vector<vector<int>>& grid)
    {
        if(x<0 || x>=m || y<0 || y>=n || grid[x][y]!=1)
        {
            return true;
        }
        return false;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int oranges=0;
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
                if(grid[i][j]==1 || grid[i][j]==2)
                {
                    oranges++;
                }
            }
        }
        int rotoranges=0,time=0;
        while(!q.empty())
        {
            int z=q.size();
            while(z--)
            {
                rotoranges++;
                pair<int,int> p=q.front();
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int x=p.first+ROW[i];
                    int y=p.second+COL[i];
                    if(isValid(x,y,m,n,grid))
                    {
                        continue;
                    }
                    q.push({x,y});
                    grid[x][y]=2;
                }
            }
            if(!q.empty())
            {
                time++;    
            }
        }
        if(rotoranges==oranges)
        {
            return time;
        }
        return -1;
        
    }
};