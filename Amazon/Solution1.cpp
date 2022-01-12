class Solution {
  public:
    int maxProfit(int k, int n, int a[]) 
    {
        int dp[k+1][n];
        for(int i=0;i<k+1;i++)
        {
            dp[i][0]=0;
        }
        for(int j=0;j<n;j++)
        {
            dp[0][j]=0;
        }
        
        for(int i=1;i<=k;i++)
        {
            int maxm=INT_MIN;
            for(int j=1;j<n;j++)
            {
                maxm=max(maxm,dp[i-1][j-1]-a[j-1]);
                dp[i][j]=max(dp[i][j-1],maxm+a[j]);
            }
        }
        
        return dp[k][n-1];
    }
};