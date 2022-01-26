int numberOfBoomerangs(vector<vector<int>>& points) 
    {
        int result=0;
       unordered_map<int, int> m;
    
        for(int i=0; i<points.size() ; i++){

            for(int j=0 ; j<points.size() ; j++)
            {
                int x=points[j][1] -points[i][1];
                int y=points[j][0] - points[i][0];
                int d = pow(x, 2) + pow(y,2); 
                m[d]++;
            }
            for(auto j:m)
            {
                result+=(j.second-1)*j.second;
            }
            m.clear();
        }
        
        return result;
    }