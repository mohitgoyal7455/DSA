class Solution {
public:
    void dfs(int i, vector<vector<int>>& adj, vector<bool>& visited, int& v, int& e) {
        visited[i] = 1;
        v++;
        e += adj[i].size();

        for(int &it : adj[i]) {
            if(!visited[it]) {
                dfs(it, adj, visited, v, e);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        int result = 0;

      
        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++) {
            if(!visited[i]){ 
                
            
            int v = 0;
            int e = 0;
            dfs(i, adj, visited, v, e);

            if((v*(v-1)) == e) {
                result++;
              }
            }
        }
        
        return result;
    }
};
