vector<int> dp;
	int mod=1e9+7;
    int solve(string s)
    {
        if(s.size() == 0)
        {
            return 1;
        }
        if(s[0] == '0')
        {
            return 0;
        }    
        if(dp[s.size()] != -1)
        {
            return dp[s.size()];    
        }
        
        int n1 = 0, n2 = 0, num = 0;
         n1 = solve(s.substr(1));
         
         num = stoi(s.substr(0, 2));
        if(num <= 26 and num >= 10)
        {
            n2 = solve(s.substr(2));
        }
        return (dp[s.size()] = n1+n2)%=mod;
    }
    
	int CountWays(string s)
	{
		dp.resize(s.size()+1, -1);
        
        	int k = solve(s);
        	return k;
		    
	}