int find(int s,int e,vector<vector<int>> &dp)
    {
        if(s>=e)
        {
            return 0;
        }
        if(dp[s][e]<INT_MAX)
        {
            return dp[s][e];
        }
        for(int i=s;i<=e;i++)
        {
            int left=find(s,i-1,dp);
            int right=find(i+1,e,dp);
            dp[s][e]=min(dp[s][e],i+max(left,right));
        }
        return dp[s][e];
    }
    int getMoneyAmount(int n) 
    {
        vector<vector<int>> dp(n+1,vector<int>(n+1,INT_MAX));
        return find(0,n,dp);
    }