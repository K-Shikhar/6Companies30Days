pair<int,int> findSmallestRange(int ar[][N], int n, int k)
    {
        int minind,mi,mx,minel,maxel,range=INT_MAX;
        int vt[k];
        memset(vt,0,sizeof(vt));
        bool fg=0;
        mx=INT_MIN;
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<k;i++)
        {
            pq.push({ar[i][0],i});
            if(mx<ar[i][0])
            mx=ar[i][0];
        }
        while(1)
        {
            mi=pq.top().first;
            minind=pq.top().second;
            pq.pop();
            if(mx-mi<range)
            {
                range=mx-mi;
                minel=mi;
                maxel=mx;
            }
            vt[minind]++;
            if(vt[minind]==n)
            break;
            if(ar[minind][vt[minind]]>mx)
            mx=ar[minind][vt[minind]];
            pq.push({ar[minind][vt[minind]],minind});
        }
        pair<int,int> pt={minel,maxel};
        return pt;
    }