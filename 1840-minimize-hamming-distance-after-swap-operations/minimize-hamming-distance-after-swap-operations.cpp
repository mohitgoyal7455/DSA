class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int findUp(int node) {
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = findUp(parent[node]); 
    }
    void unionR(int u, int v) {
        int Ultp_u = findUp(u);
        int Ultp_v = findUp(v);

        if (Ultp_u == Ultp_v) return;

        if (rank[Ultp_u] > rank[Ultp_v]) {
            parent[Ultp_v] = Ultp_u;
        } 
        else if (rank[Ultp_v] > rank[Ultp_u]) {
            parent[Ultp_u] = Ultp_v;
        } 
        else {
            parent[Ultp_u] = Ultp_v;
            rank[Ultp_v]++;  
        }
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target,
                               vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        for (const auto& it : allowedSwaps) {
            unionR(it[0], it[1]);
        }
        unordered_map<int, unordered_map<int, int>> mp;

        for (int i = 0; i < n; i++) {
            int p = findUp(i);
            mp[p][source[i]]++;
        }

        int hammingdis = 0;
        for (int i = 0; i < n; i++) {
            int p = findUp(i);
            if (mp[p][target[i]] > 0) {
                mp[p][target[i]]--;
            } else {
                hammingdis++;
            }
        }

        return hammingdis;
    }
};