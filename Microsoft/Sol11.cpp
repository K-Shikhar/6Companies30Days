vector<string> generate(int N)
{
	vector<string> v;
	
	for(int i=1;i<=N;i++)
	{
	    string s="";
	    int p=i;
	    while(p!=0)
	    {
	        int a=p%2;
	        s+=char(a+48);
	        p=p/2;
	    }
	    reverse(s.begin(),s.end());
	    
	    v.push_back(s);
	}
	
	return v;
}