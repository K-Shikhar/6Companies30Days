string nextPalin(string N) { 
        int n=N.size();
        string str="-1";
        if(n<=3) 
        {
            return str;
    
        }
        string s= N.substr(0,n/2);
        string ans="";
        
        if(next_permutation(s.begin(),s.end()))
        {
            ans+=s;
            if(n%2==1)
            {
                ans+=N[n/2];
            }
            reverse(s.begin(),s.end());
            ans+=s;
            return ans;
        }
        return str;
    }