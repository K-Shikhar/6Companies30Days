int dp[501][501];
    int findmax(vector<int> v,int s,int e)
    {
        if(s>e)
        {
            return 0;
        }
        if(dp[s][e]!=-1)
        {
            return dp[s][e];
        }
        
        int x=v[s]+min(findmax(v,s+2,e),findmax(v,s+1,e-1));
        int y=v[e]+min(findmax(v,s+1,e-1),findmax(v,s,e-2));
        
        return dp[s][e]=max(x,y);
    }
    int maxCoins(vector<int>&A,int n)
    {
	    memset(dp,-1,sizeof(dp));
	    return findmax(A,0,n-1);
    }