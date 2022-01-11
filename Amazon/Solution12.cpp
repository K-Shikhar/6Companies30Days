string colName (long long int n)
    {
        string ans="";
        while(n>0)
        {
            int k=n%26;
            
            if(k==0)
            {
                ans+='Z';
                n=n-26;
            }
            else
            {
                ans+='A'+char(k-1);
                n-=k;
            }
            n=n/26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }