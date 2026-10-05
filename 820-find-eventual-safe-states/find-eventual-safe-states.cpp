class Solution {
public:
    bool dfs(int node,vector<vector<int>>&graph,vector<int>&vis,vector<int>&pathvis,vector<int>&check){
        vis[node]=1;
        pathvis[node]=1;
        check[node]=0;
        for(auto it:graph[node]){
            if(!vis[it]){
                if(dfs(it,graph,vis,pathvis,check)==true){
                    return true;

                }
            }
            else if(pathvis[it]==1)
            { 
                return true;

                }
            }
        
        pathvis[node]=0;
        check[node]=1;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int V=graph.size();
        vector<int>vis(V,0);
        vector<int>pathvis(V,0);
        vector<int>check(V,0);

        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,graph,vis,pathvis,check);
            }
        }
        vector<int>ans;
        for(int i=0;i<V;i++){
            if(check[i]==1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};