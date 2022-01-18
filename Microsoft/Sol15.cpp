void dfs(int index,vector<int> &vis,vector<vector<int>> &v,string &ans)
    {
        vis[index]=1;
        for(auto it:v[index])
        {
            if(vis[it]==0)
            {
                dfs(it,vis,v,ans);
            }
        }
        char ch= index+'a';
        ans+=ch;
    }
    
    string findOrder(string dict[], int N, int k) {
       vector<vector<int>> v(k);
       string ans="";
       for(int i=0;i<N-1;i++)
       {
           string s1=dict[i];
           string s2=dict[i+1];
           int l=min(s1.length(),s2.length());
           for(int j=0;j<l;j++)
           {
               if(s1[j]!=s2[j])
               {
                   v[s1[j]-'a'].push_back(s2[j]-'a');
                   break;
               }
           }
           vector<int> vis(k,0);
           for(int i=0;i<k;i++)
           {
               if(vis[i]==0)
               {
                   dfs(i,vis,v,ans);
               }
           }
       }
       reverse(ans.begin(),ans.end());
       return ans;
    }