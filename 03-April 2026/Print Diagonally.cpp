class Solution {
public:
    vector<int> diagView(vector<vector<int>>& A) {
        int n = A.size();
        vector<int> result;

        for (int d = 0; d < 2 * n - 1; d++) {
            int row = (d < n) ? 0 : d - n + 1;
            int col = (d < n) ? d : n - 1;

            while (row < n && col >= 0) {
                result.push_back(A[row][col]);
                row++;
                col--;
            }
        }

        return result;
    }
};
