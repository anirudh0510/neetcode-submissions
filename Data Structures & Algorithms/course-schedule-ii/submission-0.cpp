class Solution {
public:

    bool dfs(int node , vector<vector<int>>&adj , vector<int>&vis , vector<int>&dfsvis , stack<int>&st){
        vis[node]=1;
        dfsvis[node]=1;

        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfs(it , adj , vis , dfsvis , st)){
                    return true;
                }
            }
            else if(dfsvis[it]){
                return true;
            }
        }
        dfsvis[node]=0;
        st.push(node);

        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // we will solve this q with DFS-cycle check
        //first make adj list
        vector<vector<int>> adj(numCourses);
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(numCourses , 0);
        vector<int> dfsvis(numCourses , 0);   //path
        stack<int> st;  //store the topo sort

        for(int i=0 ; i< numCourses ; i++){
            if(!vis[i]){
                if(dfs(i , adj , vis , dfsvis , st)){
                    return {};
                }
            }
        }

        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};