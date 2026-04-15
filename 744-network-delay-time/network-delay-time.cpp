class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto &it:times){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
        }
        vector<int>dis(n+1,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        dis[k]=0;
        pq.push({0,k});

        while(!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto &it:adj[node]){
                int edgewt=it.second;
                int adjnode=it.first;
                if(d+edgewt<dis[adjnode]){
                    dis[adjnode]=d+edgewt;
                    pq.push({dis[adjnode],adjnode});
                }
            }
        }
        for(int i=1;i<=n;i++){
        if(dis[i]==1e9){
            return {-1};

        }
        }
        
        int maxi=0;
        for(int i=1;i<=n;i++){
            maxi=max(maxi,dis[i]);
        }
          return maxi;
        
        
      
    }
};