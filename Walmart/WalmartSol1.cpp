void bfs(vector<vector<pair<int,double>>> &v,int start,vector<double> &p)
    {
        queue<int> q;
        q.push(start);
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            for(auto i:v[x])
            {
                int y=i.first;
                double z=i.second;
                if(p[y]<(p[x]*z))
                {
                    p[y]=p[x]*z;
                    q.push(y);
                }
            }
        }
    }
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& prob, int start, int end) 
    {
        vector<vector<pair<int,double>>> v(n);
        
        for(int i=0;i<edges.size();i++)
        {
            v[edges[i][1]].push_back({edges[i][0],prob[i]});
            v[edges[i][0]].push_back({edges[i][1],prob[i]});
        }
        vector<double> p(n,0);
        p[start]=1;
        bfs(v,start,p);
        return p[end];
    }