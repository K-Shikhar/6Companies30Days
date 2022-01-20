int mod=1000000007;
    int numOfWays(int n, int x)
    {
        long long dp[n+1];
        memset(dp, 0, sizeof(dp));
        
        dp[0] = dp[1] = 1;

        int maxLimit = pow(n, 1.0/x);

        for(int i = 2; i <= maxLimit; i++)
	{
            int curr = pow(i, x);
            
            for(int j = n; j >= curr; j--)
	    {
                dp[j] += dp[j-curr];
                dp[j]%=1000000007;
            }
        }
        
        return dp[n];
    }