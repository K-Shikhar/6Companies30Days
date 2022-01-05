string printMinNumberForPattern(string s)
    {
        int x=1;
        stack<string> stk,s2;
         for(int i=0;i<s.length();i++)
         {
             if(s[i]=='I')
             {
                 stk.push(to_string(x));
                 x++;
                 
                 while(!stk.empty())
                 {
                     string str=stk.top();
                     s2.push(str);
                     stk.pop();
                 }
             }
             else
             {
                 stk.push(to_string(x));
                 x++;
             }
         }
         
         stk.push(to_string(x));
         
         while(!stk.empty())
         {
             string str=stk.top();
             s2.push(str);
             stk.pop();
         }
         
         string ans="";
         while(s2.size()!=0)
         {
             ans+=s2.top();
             s2.pop();
         }
         
         reverse(ans.begin(),ans.end());
         
         return ans;
    }