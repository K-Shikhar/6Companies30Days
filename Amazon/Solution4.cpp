class Solution{
public:
    long long dp[30][30];
    int bracket[30][30];

    void printString(int i,int j,string &ans)
    {   
        if(i>j)
        return;
        if(i==j-1 or i==j)
        {
            ans+='A'+j-1;
            return;
        }
        ans+='(';
        printString(i,bracket[i][j],ans);
        printString(bracket[i][j],j,ans);
        ans+=')';
    }
    long long recurse(int i,int j,int arr[])
    {
        
        if(i==j-1 or i==j)
        {
            bracket[i][j]=j;
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        long long minm=INT_MAX;
        int z=0;
        for(int k=i+1;k<j;k++)
        {
            long long val=recurse(i,k,arr)+recurse(k,j,arr)+arr[i]*arr[k]*arr[j];
            if(val<=minm)
            {
                minm=val;
                z=k;
            }
        }   
        bracket[i][j]=z;
        return dp[i][j]=minm;
    }

    string matrixChainOrder(int p[], int n)
    {
        memset(dp,-1,sizeof dp);
        long long x=recurse(0,n-1,p);
        string ans="";
        printString(0,n-1,ans);
        return ans;
    }
};