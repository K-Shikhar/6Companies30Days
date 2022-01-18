vector<int> leaders(int a[], int n){
        stack<int> stk;
        int maxm=a[n-1];
        vector<int> v;
        stk.push(a[n-1]);
        for(int i=n-2;i>=0;i--)
        {
            if(maxm<=a[i])
            {
                maxm=a[i];
                stk.push(maxm);
            }
        }
        while(!stk.empty())
        {
            v.push_back(stk.top());
            stk.pop();
        }
        return v;
        
    }