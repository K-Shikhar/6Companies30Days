class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        int dp[n];
        dp[0]=arr[0];
        dp[1]=max(arr[1],arr[0]);
        dp[2]=max(arr[0]+arr[2],arr[1]);
        if(n==1)
        {
            return dp[0];
        }
        else if(n==2)
        {
            return dp[1];
        }
        else if(n==2)
        {
            return dp[2];
        }
        for(int i=3;i<n;i++)
        {
            dp[i]=max(dp[i-1],arr[i]+dp[i-2]);
        }
        
        return dp[n-1];
    }
};