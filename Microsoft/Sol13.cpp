unordered_map<int,vector<int>> adj;

    void DFS(int u,vector<int>& disc,vector<int>& low,vector<int>& parent,vector<pair<int,int>>& bridge)
    {
    	static int time = 0;
    	disc[u] = low[u] = time;
    	time+=1;
    
    	for(int v: adj[u])
    	{
    		if(disc[v]==-1)	
    		{
    			parent[v] = u;
    			DFS(v,disc,low,parent,bridge);
    			low[u] = min(low[u],low[v]);
    
    			if(low[v] > disc[u])
    				bridge.push_back({u,v});
    		}
    		else if(v!=parent[u])	
    			low[u] = min(low[u],disc[v]);
    	}
    }
    
    bool findBridges_Tarjan(int V,int c,int d)
    {
    	vector<int> disc(V,-1),low(V,-1),parent(V,-1);
    	vector<pair<int,int>> bridge;
    
    	for(int i=0;i<V;++i)
    		if(disc[i]==-1)
    			DFS(i,disc,low,parent,bridge);
    
    	
    	for(int i=0;i<bridge.size();i++)
    	{
    	        int a=bridge[i].first;
    	        int b=bridge[i].second;
    		    if((a==c && b==d)||(a==d && b==c))
    		    {
    		        return 1;
    		    }
    	}
    	return 0;
    }

    int isBridge(int V, vector<int> arr[], int c, int d) 
    {
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<arr[i].size();j++)
            {
                adj[i].push_back(arr[i][j]);
            }
        }
        return findBridges_Tarjan(V,c,d);
    }