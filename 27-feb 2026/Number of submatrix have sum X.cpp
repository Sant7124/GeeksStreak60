class Solution {
public:
    int countSquare(vector<vector<int>>& mat, int x) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<long long>> ps(n+1, vector<long long>(m+1, 0));

        // Build prefix sum matrix
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                ps[i][j] = mat[i-1][j-1] 
                         + ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1];
            }
        }

        int count = 0;
        // Iterate over all square sizes
        for(int k=1; k<=min(n,m); k++) {
            for(int i=0; i+k<=n; i++) {
                for(int j=0; j+k<=m; j++) {
                    int r1=i, c1=j, r2=i+k, c2=j+k;
                    long long sum = ps[r2][c2] - ps[r1][c2] 
                                  - ps[r2][c1] + ps[r1][c1];
                    if(sum == x) count++;
                }
            }
        }
        return count;
    }
};
