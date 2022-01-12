class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        string str="";
        vector<vector<string>> ans;
        
        set<string> st;
        for(int i=0;i<n;i++){
            st.insert(contact[i]);
        }
        
        for(int i=0;i<s.length();i++)
        {
            str=s.substr(0,i+1);
            vector<string> v;
            for(auto j:st)
            {
                int k=str.size();
                if(str==j.substr(0,k))
                {
                    v.push_back(j);
                }
            }
            if(v.size()!=0)
            {
                ans.push_back(v);
            }
            else
            {
                v.push_back("0");
                ans.push_back(v);
            }
        }
        
        return ans;
    }
};