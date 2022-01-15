int findsum(int arr[],int n,int sum,vector<vector<int>> &dp,int totalsum)
  {
      if(dp[n][sum]!=-1)
      {
          return dp[n][sum];
      }
      if(n==0)
      {
          return dp[n][sum]=abs(totalsum-2*sum);
      }
      return dp[n][sum]=min(findsum(arr,n-1,sum+arr[n-1],dp,totalsum),findsum(arr,n-1,sum,dp,totalsum));
  }
  
	int minDifference(int arr[], int n)  
	{    
	    int totalsum=0;
	    for(int i=0;i<n;i++)
	    {
	        totalsum+=arr[i];   
	    }
	    vector<vector<int>> dp(n+1,vector<int>(totalsum+1,-1));
	    return findsum(arr,n,0,dp,totalsum);
	} 