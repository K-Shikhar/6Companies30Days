bool isLeaf(vector<vector<int>>& grid, int x, int y, int width, int height) 
    {
        int k = grid[y][x];

        for (int i = y; i < (y + height); i++) 
        {
            for (int j = x; j < (x + width); j++) 
            {
                if (grid[i][j] != k) 
                {
                    return false;
                }
            }
        }
        return true;
    }
    Node* build(vector<vector<int>>& grid, int x, int y, int width, int height) 
    {
        if (isLeaf(grid, x, y, width, height)) 
        {
            return new Node(grid[y][x] == 1, true, NULL, NULL, NULL, NULL);
        }
        
        Node* root = new Node(false, false, NULL, NULL, NULL, NULL);
        root->topLeft = build(grid, x, y, width / 2, height / 2);
        root->topRight = build(grid, x + width / 2, y, width / 2, height / 2);
        root->bottomLeft = build(grid, x, y + height / 2, width / 2, height / 2);
        root->bottomRight = build(grid, x + width / 2, y + height / 2, width / 2, height / 2);
        
        return root;
    }
    
    Node* construct(vector<vector<int>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        return build(grid, 0, 0, m, n);
    }