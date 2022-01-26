int ROW[4]={0,0,1,-1};
    int COL[4]={1,-1,0,0};
    int flag=0;
    bool isValid(vector<vector<int>>& vis,vector<vector<char>>& board, string word,int index,int m,int n,int i,int j)
    {
        if(i>=0 && i<m && j>=0 && j<n && vis[i][j]==0 && index<word.length() && board[i][j]==word[index])
        {
            return 1;
        }
        return 0;
    }
    void dfs(vector<vector<int>>& vis,vector<vector<char>>& board, string word,int index,int m,int n,int i,int j)
    {
        if(index==word.length())
        {
            flag=1;
            return;
        }
        for(int k=0;k<4;k++)
        {
            int x=i+ROW[k];
            int y=j+COL[k];
            if(isValid(vis,board,word,index,m,n,x,y))
            {
                vis[x][y]=1;
                dfs(vis,board,word,index+1,m,n,x,y);
            }
        }
        vis[i][j]=0;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(word[0]==board[i][j])
                {
                    vis[i][j]=1;
                    dfs(vis,board,word,1,m,n,i,j);
                }
            }
        }
        return flag;
    }