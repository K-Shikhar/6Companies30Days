string gcdOfStrings(string str1, string str2) {
        if(str1==str2)
        {
            return str2;
        }
        string ans="";
        string s2=str2;
        while(s2.length()<str1.length())
        {
            s2+=str2;
        }
        for(int i=0;i<str1.length();i++)
        {
            
            if(s2[i]!=str1[i])
            {
                return ans;
            }
        }
        
        int l1=str1.length();
        int l2=str2.length();
        
        int k=__gcd(l1,l2);
        
        ans=str2.substr(0,k);
        return ans;
    }