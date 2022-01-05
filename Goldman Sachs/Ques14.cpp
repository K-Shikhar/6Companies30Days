int minSubArrayLen(int target, vector<int>& nums) {
        int i=-1,j=-1;
        
        if(nums.size()==1)
        {
            if(nums[0]==target)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        int n=nums.size();
        int s=0;
        for(int i=0;i<n;i++)
        {
            s+=nums[i];
        }
        if(s<target)
        {
            return 0;
        }
        int sum=0;
        int l=INT_MAX;
  
        while(j<n-1 && i<=j)
        {
            if(sum>=target)
            {
                l=min(l,j-i); 
                i++;
                 sum=sum-nums[i];

            }
            else if(sum<target)
            {
                j++;
                sum=sum+nums[j];
            }
        }
        while(sum>=target){
            l=min(l,j-i);
            i++;
            sum-=nums[i];
        }

        if(l==INT_MAX)
        return 0;
        else
        {
            return l;
        }
    }