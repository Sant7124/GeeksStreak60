class Solution {
public:
    vector<int> stableMarriage(vector<vector<int>>& men, vector<vector<int>>& women) {
        
        int n = men.size();
        
        vector<int> womanPartner(n, -1); // which man is matched with woman
        vector<int> manPartner(n, -1);   // result
        vector<int> nextProposal(n, 0);  // next woman to propose

        // Create ranking for women
        vector<vector<int>> rank(n, vector<int>(n));
        for (int w = 0; w < n; w++) {
            for (int i = 0; i < n; i++) {
                rank[w][women[w][i]] = i;
            }
        }

        queue<int> freeMen;
        for (int i = 0; i < n; i++) {
            freeMen.push(i);
        }

        while (!freeMen.empty()) {
            int m = freeMen.front();
            freeMen.pop();

            int w = men[m][nextProposal[m]];
            nextProposal[m]++;

            if (womanPartner[w] == -1) {
                // woman is free
                womanPartner[w] = m;
                manPartner[m] = w;
            } else {
                int m2 = womanPartner[w];

                if (rank[w][m] < rank[w][m2]) {
                    // woman prefers new man
                    womanPartner[w] = m;
                    manPartner[m] = w;

                    manPartner[m2] = -1;
                    freeMen.push(m2);
                } else {
                    // rejected
                    freeMen.push(m);
                }
            }
        }

        return manPartner;
    }
};
