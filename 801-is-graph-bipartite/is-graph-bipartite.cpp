class Solution {
public:
    bool bfs(int start, vector<vector<int>>& graph, vector<int>& vis) {
        queue<int> q;
        q.push(start);

        vis[start] = 0; 
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto it : graph[node]) {
               
                if (vis[it] == -1) {
                    vis[it] = 1 - vis[node]; 
                    q.push(it);
                }
                else if (vis[it] == vis[node]) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> vis(V, -1); 

        for (int i = 0; i < V; i++) {
            if (vis[i] == -1) {
                if (bfs(i, graph, vis)==false)
                    return false;
            }
        }
        return true;
    }
};