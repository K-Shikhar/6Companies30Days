int atoi(string str) 
    {
        int sum=0;
        if(str[0]=='-')
        {
            return stoi(str);
        }
        for(int i=0;i<str.length();i++)
        {
            if(isalpha(str[i]))
            {
                return -1;
            }
        }
        //reverse(str.begin(),str.end());
        for(int i=0;i<str.length();i++)
        {
            int a=str[i]-'0';
            sum=sum*10+a;
        }
        
        return sum;
    }