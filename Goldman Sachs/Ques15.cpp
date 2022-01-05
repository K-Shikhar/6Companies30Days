bool canPair(vector<int> nums, int k) 
    {
        if(nums.size()%2==1)
        {
            return false;
        }
        int a[k]={0};
        for(int i=0;i<nums.size();i++)
        {
            int d=nums[i]%k;
            a[d]++;
        }
        
        for(int i=1;i<k;i++)
        {
            if(a[i]!=a[k-i])
            {
                return false;
            }
        }
        
        if(a[0]%2==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }