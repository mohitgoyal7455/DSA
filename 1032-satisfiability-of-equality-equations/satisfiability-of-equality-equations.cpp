class Solution {
public:
    vector<int>parent,rank;
    int findUparent(int node){
        if(node==parent[node]){
            return node ;
        }
        return parent[node]=findUparent(parent[node]);
    }
    void unionbyrank(int u,int v){
        int Uparent_u=findUparent(u);
        int Uparent_v=findUparent(v);
        if(Uparent_u == Uparent_v){
            return ;
        }
        if(rank[Uparent_u]>rank[Uparent_v]){
            parent[Uparent_v]=Uparent_u;
        }
        else if(rank[Uparent_u]<rank[Uparent_v]){
            parent[Uparent_u]=Uparent_v;
        }
        else{
            parent[Uparent_u]=Uparent_v;
            rank[Uparent_v]++;

        }
    }
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26,0);
        for(int i=0;i<26;i++){
            parent[i]=i;
        }
        for(string &s : equations){
            if(s[1] == '='){
                unionbyrank(s[0]-'a', s[3]-'a');
            }
        }
            for(string &s : equations){
            if(s[1] == '!'){
                if(findUparent(s[0]-'a') == findUparent(s[3]-'a')){
                    return false;
                }
            }
        }
        return true;

    }
};