class Solution {
public:
    void dfs(int node,vector<vector<int>> &adj,vector<int>&vis){
        vis[node]=1;
        for(auto &it:adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis);
            }
        }
    }
    int makeConnected(int V, vector<vector<int>>& connections) {
        vector<vector<int>> adj(V);
        for(auto &it: connections ){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(V,0);
            if(connections.size() <V-1){
                return -1;
            }
            int count =0;
        for(int i=0;i<V;i++){
            
            if(!vis[i]){
                dfs(i,adj,vis);
                count++;
            }
            
            

        }
        return count-1;
          }
};