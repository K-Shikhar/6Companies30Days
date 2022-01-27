int dp[507][507];
    int find(vector<int>& piles,int start,int end)
    {
        if(start > end)
        {
            return 0;
        }
        if(dp[start][end]!=-1)
        {
            return dp[start][end];
        }
        
        int x=piles[start]+min(find(piles,start+1,end-1),find(piles,start,end-2));
        int y=piles[end]+min(find(piles,start+2,end),find(piles,start+1,end-1));
        
        return dp[start][end]=max(x,y);
    }
    bool stoneGame(vector<int>& piles) 
    {
        int start=0,end=piles.size()-1;
        memset(dp,-1,sizeof(dp));
        return find(piles,start,end);
    }