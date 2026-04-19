class Solution {
public:
    int kBitFlips(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> isFlipped(n, 0);
        int flipCount = 0, currFlips = 0;

        for (int i = 0; i < n; i++) {
            if (i >= k) currFlips -= isFlipped[i - k]; // remove expired flips

            // If current bit after flips is 0, we must flip here
            if ((arr[i] + currFlips) % 2 == 0) {
                if (i + k > n) return -1; // not enough space to flip
                flipCount++;
                currFlips++;
                isFlipped[i] = 1; // mark flip starting here
            }
        }
        return flipCount;
    }
};
