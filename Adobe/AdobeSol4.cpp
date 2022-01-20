int dp[101][5007];
    bool subset(int sum,int a[],int n)
    {
        if(dp[n][sum]!=-1)
        {
            return dp[n][sum];
        }
        if(n<0)
        {
            return 0;
        }
        if(sum==0)
        {
            return 1;
        }
        if(a[n-1]>sum)
        {
            return dp[n][sum]=subset(sum,a,n-1);
        }
        return dp[n][sum]=subset(sum-a[n-1],a,n-1)||subset(sum,a,n-1);
        
    }
    int equalPartition(int N, int arr[])
    {
        memset(dp,-1,sizeof(dp));
        int sum=0;
        for(int i=0;i<N;i++)
        {
            sum+=arr[i];
        }
        if(sum%2==1)
        {
            return 0;
        }
        int k=sum/2;
        return subset(k,arr,N);
    }