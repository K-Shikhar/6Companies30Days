class Solution{
public:
    int isValid(vector<vector<int>> mat){
        bool row[10][10] = {false},col[10][10] = {false},grid[10][10] = {false};
        
        for(int i = 0; i < 9; i++) 
        {
            for(int j = 0; j < 9; j++) 
            {
                int num = mat[i][j];
                if(num == 0) continue;
                int in = (i/3) * 3 + (j/3);
                if(row[i][num] || col[j][num] || grid[in][num])
                    return 0;
                row[i][num] = true;
                 col[j][num] = true;
                  grid[in][num] = true;
            }
        }
        return 1;
    }
};