class Solution {
public:
    string largestSwap(string s) {
        int n = s.size();
        vector<int> rightMaxIndex(n);
        int maxIdx = n - 1;

        // Track rightmost max digit index
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] > s[maxIdx]) maxIdx = i;
            rightMaxIndex[i] = maxIdx;
        }

        // Find first position where swap helps
        for (int i = 0; i < n; i++) {
            if (s[i] < s[rightMaxIndex[i]]) {
                swap(s[i], s[rightMaxIndex[i]]);
                break;
            }
        }
        return s;
    }
};
