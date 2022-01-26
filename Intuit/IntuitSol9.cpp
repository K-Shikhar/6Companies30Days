int ROW[4]={0,0,-1,1};
    int COL[4]={-1,1,0,0};
    int rows,cols;
    void dfs(int i, int j, pair<int, int> prev, vector<vector<bool>> &visited, vector<vector<int>> &heights)
    {
        if (i < 0 || i >= rows || j < 0 || j >= cols || visited[i][j])
        {
            return;
        }
        if (heights[prev.first][prev.second] >heights[i][j])
        {
            return;
        }
        visited[i][j] = true;
        for (int k=0;k<4;k++)
        {
            dfs(i+ROW[k],j+COL[k],{i, j}, visited, heights);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
         rows = heights.size();
        cols = heights[0].size();

        vector<vector<bool>> paci(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlan(rows, vector<bool>(cols, false));

        int j = 0;
        while (j < cols)
        {
            dfs(0, j, {0, j}, paci, heights);
            dfs(rows - 1, j, {rows - 1, j}, atlan, heights);
            j++;
        }

        int i = 0;
        while (i < rows)
        {
            dfs(i, 0, {i, 0}, paci, heights);
            dfs(i, cols - 1, {i, cols - 1}, atlan, heights);
            i++;
        }

        vector<vector<int>> result;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (paci[i][j] && atlan[i][j])
                    result.push_back({i, j});
            }
        }
        return result;
    }