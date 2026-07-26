class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis) {

        vis[node] = 1;
        pathVis[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfs(it, adj, vis, pathVis))
                    return true;
            }
            else if (pathVis[it]) {
                return true;
            }
        }

        pathVis[node] = 0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        //first we have to make the directed graphh first to do anything
        vector<vector<int>> adj(numCourses);
        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }

        //now have to apply topological sort --> 2 wayss --By BFS TOPO tempelate and other by simply checking cycle with DFS

        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (dfs(i, adj, vis, pathVis))
                    return false;
            }
        }

        return true;
    }
};