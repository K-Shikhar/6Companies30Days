vector<int> subarraySum(int arr[], int n, long long s)
    {
        int i=0,j=0;
        int sum=0;
        vector<int> v;
        while(j<n)
        {
            sum+=arr[j++];
            while(sum>s)
            {
                sum-=arr[i++];
            }
            if(sum==s)
            {
                v.push_back(i+1);
                v.push_back(j);
                return v;
            }
        }
            v.push_back(-1);
            return v;
    }