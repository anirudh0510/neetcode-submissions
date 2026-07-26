class Solution {
public:
    bool dfs(vector<vector<int>>& adj, int u, int v, vector<bool>& vis) {
        if (u == v) return true;

        vis[u] = true;

        for (auto it : adj[u]) {
            if (!vis[it]) {
                if (dfs(adj, it, v, vis)) {
                    return true;
                }
            }
        }
        return false;
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {

        vector<vector<int>> adj(numCourses);

        // build graph
        for (auto it : prerequisites) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
        }

        int Q = queries.size();
        vector<bool> ans(Q);

        for (int i = 0; i < Q; i++) {
            int u = queries[i][0];
            int v = queries[i][1];

            vector<bool> vis(numCourses, false); // reset for each query
            ans[i] = dfs(adj, u, v, vis);
        }

        return ans;
    }
};