class Solution {
public:

    bool dfs(int node, int target, vector<vector<int>>& adj, vector<int>& vis) {

        if (node == target)
            return true;

        vis[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfs(it, target, adj, vis))
                    return true;
            }
        }

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();

        vector<vector<int>> adj(n + 1);

        for (auto it : edges) {

            int u = it[0];
            int v = it[1];

            vector<int> vis(n + 1, 0);

            // If u and v are already connected,
            // then this edge is redundant.
            if (!adj[u].empty() && !adj[v].empty() && dfs(u, v, adj, vis)) {
                return {u, v};
            }

            // Otherwise add the edge.
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return {};
    }
};