class Solution {
public:
    int orangesRot(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        queue<pair<int,int>> q;
        int fresh = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 2) {
                    q.push({i, j});
                }
                else if(mat[i][j] == 1) {
                    fresh++;
                }
            }
        }
        
        if(fresh == 0) return 0;
        
        int time = 0;
        vector<int> drow = {-1, 1, 0, 0};
        vector<int> dcol = {0, 0, -1, 1};
        
        while(!q.empty()) {
            int size = q.size();
            bool rotted = false;
            
            for(int i = 0; i < size; i++) {
                auto it = q.front();
                q.pop();
                
                int r = it.first;
                int c = it.second;
                
                for(int k = 0; k < 4; k++) {
                    int nr = r + drow[k];
                    int nc = c + dcol[k];
                    
                    if(nr >= 0 && nc >= 0 && nr < n && nc < m && mat[nr][nc] == 1) {
                        mat[nr][nc] = 2;
                        q.push({nr, nc});
                        fresh--;
                        rotted = true;
                    }
                }
            }
            
            if(rotted) time++;
        }
        
        return (fresh == 0) ? time : -1;
    }
};
