int longestMountain(vector<int>& a) {
        int l=a.size();
        int i=1;
        if(l<3)
        {
            return 0;
        }
        int ans=0;
        while(i<l)
        {
            int inc=0,dec=0;
            while(i<l &&a[i]>a[i-1])
            {
                i++;
                inc++;
            }
            while(i<l && a[i]<a[i-1])
            {
                i++;
                dec++;
            }
            
            if(dec!=0 && inc!=0)
            {
                ans=max(ans,dec+inc+1);
            }
            else if(dec==0 && inc==0)
            {
                i++;
            }
        }
        
        return ans;
    }