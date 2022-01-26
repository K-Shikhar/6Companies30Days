vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        vector<int>indegree(numCourses,0);
        for(auto &x : prerequisites)
        {
            adj[x[1]].push_back(x[0]);
            indegree[x[0]]++;
        }
        
        queue<int>q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(int &x : adj[node])
            {
                indegree[x]--;
                if(indegree[x] == 0)
                {
                    q.push(x);
                }
            }
        }
        vector<int> empty;
        
        if(ans.size() == numCourses)
            return ans;
        
        return empty;
    }