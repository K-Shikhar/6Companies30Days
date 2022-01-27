static bool compare(string& a,string& b)
    {
        if(a.length()==b.length()){
            return a>b;
        }
        return a.length()>b.length();
    }
    string kthLargestNumber(vector<string>& nums, int k) 
    {
        sort(nums.begin(),nums.end(),compare);
        return nums[k-1];
    }