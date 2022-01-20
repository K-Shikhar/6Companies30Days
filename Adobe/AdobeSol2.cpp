int lengthOfLongestAP(int arr[], int n) {
        if(n==1)
        {
            return 1;
        }
        if(n==2)
        {
            return 2;
        }
        map<int,int> m;
        for(int i=0;i<n;i++)
        {
            m[arr[i]]++;
        }
        int maxm=INT_MIN;
        for(int i=0;i<n;i++)
        {
            
            for(int j=i+1;j<n;j++)
            {
                int len=1;
                int diff=arr[j]-arr[i];
                int k=arr[j];
                while(m.find(k)!=m.end() && k<=arr[n-1])
                {
                    k+=diff;
                    len++;
                }
                maxm=max(maxm,len);
            }
        }
        return maxm;
    }