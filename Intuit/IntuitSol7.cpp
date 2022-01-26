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
    int shipWithinDays(vector<int>& weights, int days) {
        int l=0,r=25000007;
        
        while(l<r)
        {
            int mid=(l+r)/2;
            
            if(findsum(weights,days,mid))
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