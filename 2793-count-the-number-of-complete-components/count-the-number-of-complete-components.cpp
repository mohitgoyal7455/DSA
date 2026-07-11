class Solution {
public:
    void dfs(int &i,vector<vector<int>>&adj,vector<int>&vis,int &v, int &e ){
        vis[i]=1;
        e+=adj[i].size();
        v++;
        for(auto it:adj[i]){
            if(!vis[it]){
                dfs(it,adj,vis,v,e);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        
        for(auto it:edges){
        int u=it[0];
        int v=it[1];    
        adj[u].push_back(v);
        adj[v].push_back(u);
        }
        int result=0;

        vector<int>vis(n,0);
        for(int i=0;i<n;i++){

            if(!vis[i]){
                int e=0;
                int v=0;
                dfs(i,adj,vis,v,e);
                if((v*(v-1)==e)){
                    result++;
                }
            }
        }
        return result;
        
    }
};