int findsum(vector<int>& nums, int m,int mid)
    {
        int count=0,sumarr=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>mid)
            {
                return 0;
            }
            if(sumarr+nums[i] <= mid)
            {
                sumarr+=nums[i];
            }
            else
            {
                count++;
                sumarr=nums[i];
            }
        }
        count++;
        if(count<=m)
        {
            return 1;
        }
        return 0;
    }
    int splitArray(vector<int>& nums, int m) 
    {
        int l=0,r=int(1e9)+7;
        
        while(l<r)
        {
            int mid=(l+r)/2;
            
            if(findsum(nums,m,mid))
            {
                r=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        
        return l;
    }