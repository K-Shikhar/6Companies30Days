vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        
        vector<int> ans;
        
        deque<int> dq;
        int i=0,j=0;
        while(j<n)
        {
            while(!dq.empty() && dq.back()<arr[j])
            {
                dq.pop_back();
            }
            
            dq.push_back(arr[j]);
            
            if(j-i+1<k)
            {
                j++;
            }
            else
            {
                ans.push_back(dq.front());
                
                if(arr[i]==dq.front())
                {
                    dq.pop_front();
                }
                i++;
                j++;
            }
        }
        return ans;