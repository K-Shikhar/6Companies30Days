typedef long long ll;
    const ll mod = 1000000007;
    
    
    ll recur(int N,int k,int p,int idx,vector<vector<ll>> &dp)
    {
        if(idx == N) return 1;
        
        if(dp[idx][p] != -1)
            return  dp[idx][p];
        
        if(p >= k)
        {
            return dp[idx][p] = (recur(N,k,0,idx+1,dp)%mod*21%mod)%mod;
        }
        else
        {
            return dp[idx][p] = ((recur(N,k,p+1,idx+1,dp))%mod*5%mod  + (recur(N,k,0,idx+1,dp)%mod)%mod * 21%mod)%mod;
        }
    }
    
    int kvowelwords(int N, int K) 
    {
        vector<vector<ll>> dp(N+1,vector<ll>(K+1,-1));
        return recur(N,K,0,0,dp)%mod;
    }
