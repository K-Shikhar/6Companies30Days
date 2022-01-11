class Solution{
public:
    int isValid(vector<vector<int>> mat){
        int row[9][9]={0};
        int col[9][9]={0};
        int k[9][9]={0};
        
        for(int i = 0; i < 9; i++) 
        {
            for(int j = 0; j < 9; j++) 
            {
                if(mat[i][j] == 0) continue;
                int in = (i/3) * 3 + (j/3);
                if(row[i][mat[i][j]-1] || col[j][mat[i][j]-1] || k[in][mat[i][j]-1])
                {
                    return 0;
                }
                row[i][mat[i][j]-1] = 1;
                col[j][mat[i][j]-1] = 1;
                k[in][mat[i][j]-1] = 1;
            }
        }
        return 1;
    }
};
