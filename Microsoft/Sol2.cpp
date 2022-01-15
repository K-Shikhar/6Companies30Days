bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    vector<int>adj[N];
        vector<int>indegree(N,0);
        for(auto &x : prerequisites)
        {
            adj[x.second].push_back(x.first);
            indegree[x.first]++;
        }
        
        queue<int>q;
        for(int i=0;i<N;i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        
        vector<int>res;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            res.push_back(node);
            for(int &x : adj[node])
            {
                indegree[x]--;
                if(indegree[x] == 0)
                {
                    q.push(x);
                }
            }
        }
        if(res.size()==N)
        {
            return 1;
        }
        else
        {
            return 0;
        }
	}