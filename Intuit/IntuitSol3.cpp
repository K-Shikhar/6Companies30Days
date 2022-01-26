int missingNumber(const string& s)
{
    int n=s.size();
    for(int i=1;i<=min(n,6);i++)
    {
        string st=s.substr(0,i);
        int sum=stoi(st);
        int cnt=0,k=-1,flag=0;
        
        int j=0;
        while(j<n)
        {
            string str=to_string(sum);
            if(j<n-str.size()+1)
            {
                string st=s.substr(j,str.size());
                if(st==str)
                {
                    j+=str.size();
                }
                else
                {
                    cnt++;
                    if(cnt>1)
                    {
                        break;    
                    }
                    if(cnt==1)
                    {
                        k=sum;    
                    }
                }
            }
            else
            {
                flag=1;
                break;
            }
            sum++;
        }
        if(!flag && cnt==1)
        return k;
    }
    return -1;
}