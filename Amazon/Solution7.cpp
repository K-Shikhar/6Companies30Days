string FirstNonRepeating(string s)
{
		    deque<int> dq;
		    int m[26]={0};
		    string ans="";
		    for(int i=0;i<s.length();i++)
		    {
		        if(m[s[i]-'a']==0)
		        {
		            dq.push_back(s[i]);
		        }
		        m[s[i]-'a']++;
		        while(dq.size()>0 && m[dq.front()-'a']>1)
		        {
		            dq.pop_front();
		        }
		        if(dq.size()==0)
		        {
		            ans+='#';
		        }
		        else
		        {
		             ans+=dq.front();     
		        }
		       
		    }
		    return ans;
		}
