int minSwaps(vector<vector<int>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        
        vector<int> v;
        
        for(int i=0;i<m;i++)
        {
            int count=0;
            for(int j=n-1;j>=0;j--)
            {
                if(grid[i][j]==0)
                {
                    count++;
                }
                else
                {
                    break;
                }
            }
            v.push_back(count);
        }
        int ans=0;
        for(int i=0;i<m;i++)
        {
            if(v[i]<n-i-1)
            {
                int j=i;
                while(j<n && v[j]<n-1-i)
                {
                    j++;
                }
                if(j==n)
                {
                    return -1;
                }
                while(i<j)
                {
                    swap(v[j],v[j-1]);
                    j--;
                    ans++;
                }
            }
        }
        
        return ans;
    }