class Solution {
  public:
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        
        // Step 1: Create adjacency list
        vector<int> adj[V];
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        vector<int> tin(V, -1), low(V, -1);
        vector<int> visited(V, 0);
        vector<int> mark(V, 0); // to mark articulation points
        
        int timer = 0;
        
        // DFS function
        function<void(int,int)> dfs = [&](int node, int parent){
            
            visited[node] = 1;
            tin[node] = low[node] = timer++;
            int child = 0;
            
            for(auto it : adj[node]){
                if(it == parent) continue;
                
                if(!visited[it]){
                    dfs(it, node);
                    
                    low[node] = min(low[node], low[it]);
                    
                    // Case 2: Non-root
                    if(low[it] >= tin[node] && parent != -1){
                        mark[node] = 1;
                    }
                    
                    child++;
                }
                else{
                    // Back edge
                    low[node] = min(low[node], tin[it]);
                }
            }
            
            // Case 1: Root node
            if(parent == -1 && child > 1){
                mark[node] = 1;
            }
        };
        
        // Graph can be disconnected
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                dfs(i, -1);
            }
        }
        
        vector<int> ans;
        for(int i = 0; i < V; i++){
            if(mark[i]) ans.push_back(i);
        }
        
        if(ans.size() == 0) return {-1};
        
        return ans;
    }
};
