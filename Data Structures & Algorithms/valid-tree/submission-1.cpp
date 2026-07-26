class Solution {
public:
    void dfs(int node , vector<vector<int>>&adj , vector<int>&vis){
        vis[node]=1;
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it , adj , vis);
            }
        }
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1){
            return false;
        }
        vector<vector<int>>adj(n);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            adj[v].push_back(u);
            adj[u].push_back(v);
        }
        vector<int>vis(n , 0);
        dfs(0 , adj , vis);
        for(int i=0  ; i<n ; i++){
            if(!vis[i]){
                return false;
            }
        }
        return true;
    }
};
