int findInMountainArray(int target, MountainArray &mountainArr) 
    {
        if(mountainArr.length()<3)
        {
            return -1;
        }
        
        int low=0,high=mountainArr.length()-1;

        while(low!=high)
        {
            int mid=(low+high)/2;
            
            int k=mountainArr.get(mid);
            
            if(k<mountainArr.get(mid+1))
            {
                low=mid+1;
            }
            else if(k>mountainArr.get(mid+1))
            {
                high=mid;
            }
        }
        
        int peak=low;
        int ans=-1;
        low=0;
        high=peak;
        
        while(low<=high)
        {
            int mid=(low+high)/2;
            int k=mountainArr.get(mid);
            if(k<target)
            {
                low=mid+1;
            }
            else if(k>target)
            {
                high=mid-1;
            }
            else
            {
                ans=mid;
                break;
            }
        }
        if(ans!=-1)
        {
            return ans;
        }
        low=peak+1;
        high=mountainArr.length()-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            int k=mountainArr.get(mid);
            if(k>target)
            {
                low=mid+1;
            }
            else if(k<target)
            {
                high=mid-1;
            }
            else
            {
                ans=mid;
                break;
            }
        }
        return ans;
    }