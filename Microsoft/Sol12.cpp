vector<vector<int>> fourSum(vector<int> &arr, int k) {
        
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());
        set<vector<int>> st;
        int n=arr.size();
        for(int i=0;i<n-3;i++)
        {
            for(int j=i+1;j<n-2;j++)
            {
                int a=j+1;
                int b=n-1;
                while(a<b)
                {
                    int sum=arr[i]+arr[j]+arr[a]+arr[b];
                    if(sum==k)
                    {
                        vector<int> v;
                        v.push_back(arr[i]);
                        v.push_back(arr[j]);
                        v.push_back(arr[a]);
                        v.push_back(arr[b]);
                        st.insert(v);
                        a++;
                        b--;
                    }
                    else if(sum>k)
                    {
                        b--;
                    }
                    else
                    {
                        a++;
                    }
                }
            }
        }
        for(auto i:st)
        {
            ans.push_back(i);
        }
        
        return ans;
    }