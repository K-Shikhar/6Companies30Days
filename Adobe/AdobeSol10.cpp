 vector<string> winner(string arr[],int n)
    {
        map<string,int> m;
        
        for(int i=0;i<n;i++)
        {
            m[arr[i]]++;
        }
        
        int num=0;
        string str;
        for(auto i:m)
        {
            string s=i.first;
            int d=i.second;
            if(d>num)
            {
                num=d;
                str=s;
            }
            
            if(num==d && str>s)
            {
                str=s;
            }
        }
        vector<string> ans;
        
        ans.push_back(str);
        ans.push_back(to_string(num));
        
        return ans;
    }