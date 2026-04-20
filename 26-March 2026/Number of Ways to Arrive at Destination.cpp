class Solution {
public:
    int countPaths(int V, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;

        vector<vector<pair<int,int>>> adj(V);

        // Build graph
        for(auto &e : roads) {
            int u = e[0], v = e[1], t = e[2];
            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }

        // Min heap: {distance, node}
        priority_queue<pair<long long,int>, 
                       vector<pair<long long,int>>, 
                       greater<pair<long long,int>>> pq;

        vector<long long> dist(V, LLONG_MAX);
        vector<int> ways(V, 0);

        dist[0] = 0;
        ways[0] = 1;

        pq.push({0, 0});

        while(!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            for(auto &[v, wt] : adj[u]) {
                if(d + wt < dist[v]) {
                    dist[v] = d + wt;
                    ways[v] = ways[u];
                    pq.push({dist[v], v});
                }
                else if(d + wt == dist[v]) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }

        return ways[V-1];
    }
};
