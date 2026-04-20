class Solution {
public:
    int longestCycle(int V, vector<vector<int>>& edges) {
        vector<int> to(V, -1);
        
        // Build graph
        for (auto &e : edges) {
            to[e[0]] = e[1];
        }
        
        vector<int> vis(V, 0);     // visited
        vector<int> time(V, 0);    // visit time
        
        int ans = -1;
        
        for (int i = 0; i < V; i++) {
            if (vis[i]) continue;
            
            int node = i;
            int step = 1;
            
            unordered_map<int, int> mp; // node -> step
            
            while (node != -1 && !vis[node]) {
                vis[node] = 1;
                mp[node] = step++;
                node = to[node];
            }
            
            // Check cycle
            if (node != -1 && mp.count(node)) {
                ans = max(ans, step - mp[node]);
            }
        }
        
        return ans;
    }
};
