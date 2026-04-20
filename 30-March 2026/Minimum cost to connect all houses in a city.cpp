class Solution {
public:
    int manhattan(vector<int>& a, vector<int>& b) {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }

    int minCost(vector<vector<int>>& houses) {
        int n = houses.size();
        
        vector<int> minDist(n, INT_MAX);
        vector<bool> visited(n, false);
        
        minDist[0] = 0;
        int totalCost = 0;

        for (int i = 0; i < n; i++) {
            int u = -1;

            // pick minimum distance node
            for (int j = 0; j < n; j++) {
                if (!visited[j] && (u == -1 || minDist[j] < minDist[u])) {
                    u = j;
                }
            }

            visited[u] = true;
            totalCost += minDist[u];

            // update distances
            for (int v = 0; v < n; v++) {
                if (!visited[v]) {
                    int dist = manhattan(houses[u], houses[v]);
                    minDist[v] = min(minDist[v], dist);
                }
            }
        }

        return totalCost;
    }
};
