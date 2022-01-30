int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) 
    {
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++)
        {
            v.push_back({efficiency[i],speed[i]});
        }
        
        sort(v.begin(),v.end());
        
        reverse(v.begin(),v.end());
        
        priority_queue<int,vector<int>,greater<int>> pq;
        
        long long ans=0,sum=0;
        for(auto i:v)
        {
            int e=i.first;
            int s=i.second;
            sum+=s;
            pq.push(s);
            if(pq.size()>k)
            {
                sum-=pq.top();
                pq.pop();
            }
            ans=max(ans,sum*e);
        }
        return ans%1000000007;
    }