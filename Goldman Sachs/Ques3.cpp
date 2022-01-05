int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        
        long long p=1,j=0;
        int ans=0;
        for(int i=0;i<a.size();i++)
        {
            p=p*a[i];
            if(p>=k)
            {
                while(i>j && p>=k)
                {
                    p=p/a[j];
                    j++;
                }
            }
            if(p<k)
            {
                ans+=i-j+1;
            }
        }
        return ans;
    }