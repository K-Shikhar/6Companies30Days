vector<vector<string> > Anagrams(vector<string>& str) {
        vector<string> s;
        map<string,vector<string>> m;
        vector<vector<string>> ans(s.size());
        for(int i=0;i<str.size();i++)
        {
            s.push_back(str[i]);
        }
        for(int i=0;i<s.size();i++)
        {
            sort(s[i].begin(),s[i].end());
        }
        int p=1;
        for(int i=0;i<s.size();i++)
        {
            m[s[i]].push_back(str[i]);
        }
        
        for(auto i:m)
        {
            vector<string> v;
            for(auto it=i.second.begin();it!=i.second.end();++it)
            {
                v.push_back(*it);
            }
            ans.push_back(v);
        }
        
        return ans;
    }