int rec(int x,int y,vector<vector<int>> &t)
    {
        if(x<=1 || y<=1)
        {
            return t[x][y]=1;
        }
        
        if(t[x][y]!=-1)
        {
            return t[x][y];
        }
        else
        {
            return t[x][y]=rec(x,y-1,t)+rec(x-1,y,t);
        }
    }
    int NumberOfPath(int m, int n)
    {
        vector<vector<int>> t(m+1,vector<int>(n+1,-1));
        return rec(m,n,t);
    }