long long power(int N,int R)
    {
        long long p=1;
        if(R==0)
        {
            return 1;
        }
        if(R==1)
        {
            return N;
        }
         long long temp = power(N, R/2);
        if (R % 2 == 0)
            return ((temp)%mod * (temp)%mod)%mod;
        else
            return (N* (temp)%mod * (temp)%mod)%mod;
    }