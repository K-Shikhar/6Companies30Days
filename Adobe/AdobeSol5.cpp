int dp[1007][1007];
    int calculate(int n,int x,int index)
    {
        if(n==0)
        {
            return 1;
        }
        long long num=1;
        if(dp[n][index]!=-1)
        {
            return dp[n][index];
        }
        int p=x;
        while(p--)
        {
            num*=index;
        }
        int sum=0;
        if(num<=n)
        {
            sum+=calculate(n-num,x,index+1);
            sum+=calculate(n,x,index+1);
        }
        return dp[n][index]=sum;
    }
    int numOfWays(int n, int x)
    {
        memset(dp,-1,sizeof(dp));
        
       return calculate(n,x,1);
    }
