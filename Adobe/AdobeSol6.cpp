vector<string> ans;
    string str="";
    void generate(int open,int close)
    {
        if(open==0 and close==0)
        {
            ans.push_back(str);
        }
        if(open>0)
        {
            str.push_back('(');
            generate(open-1,close);
            str.pop_back();
        }
        if(close>open)
        {
            str.push_back(')');
            generate(open,close-1);
            str.pop_back();
        }
    }
    
    vector<string> AllParenthesis(int n) 
    {
        generate(n,n);
        return ans;
    }