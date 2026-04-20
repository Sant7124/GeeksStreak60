class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        
        // Build graph
        for(auto &p : prerequisites) {
            int x = p[0], y = p[1];
            adj[y].push_back(x);   // y -> x
            indegree[x]++;
        }
        
        queue<int> q;
        
        // Push nodes with indegree 0
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }
        
        int count = 0;
        
        // BFS
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            count++;
            
            for(auto neigh : adj[node]) {
                indegree[neigh]--;
                if(indegree[neigh] == 0)
                    q.push(neigh);
            }
        }
        
        return count == n;
    }
};
