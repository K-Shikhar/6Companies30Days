vector<string> ans;
    
    void create(int a[],string arr[],int n,int index,string str)
    {
        if(index == n)
        {
            ans.push_back(str);
            return;
        }
        
        string s=arr[a[index]];
        for(int i=0;i<s.length();i++)
        {
            str+=s[i];
            create(a,arr,n,index+1,str);
            str=str.substr(0,str.length()-1);
        }
    }
    vector<string> possibleWords(int a[], int N)
    {
        string arr[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string k="";
        create(a,arr,N,0,k);
        return ans;
    }