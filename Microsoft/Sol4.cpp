class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        int left=0,right=c-1,up=0,down=r-1;
        vector<int> v;
        while(left<=right && up<=down)
        {
            for(int i=left;i<=right;i++)
            {
                v.push_back(matrix[up][i]);
            }
            up++;
            if(left>right || up>down)
            {
                break;
            }
            for(int i=up;i<=down;i++)
            {
                v.push_back(matrix[i][right]);
            }
            right--;
            
            if(left>right || up>down)
            {
                break;
            }
            for(int i=right;i>=left;i--)
            {
                v.push_back(matrix[down][i]);
            }
            down--;
            
            if(left>right || up>down)
            {
                break;
            }
            for(int i=down;i>=up;i--)
            {
                v.push_back(matrix[i][left]);
            }
            left++;
        }
        return v;
    }
};