vector<int> find3Numbers(vector<int> arr, int N) 
    {
        int prefix[N];
        int postfix[N];
        prefix[0]=arr[0];
        postfix[N-1]=arr[N-1];
        for(int i=1;i<N;i++)
        {
            prefix[i]=min(prefix[i-1],arr[i]);
        }
        
        for(int i=N-2;i>=0;i--)
        {
            postfix[i]=max(postfix[i+1],arr[i]);
        }
        vector<int> v;
        for(int i=0;i<N;i++)
        {
            if(arr[i]>prefix[i] and postfix[i]>arr[i])
            {
                v={prefix[i],arr[i],postfix[i]};
                break;
            }
        }
        return v;
    }