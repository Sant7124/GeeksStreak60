class Solution {
public:
    void pushZerosToEnd(vector<int>& arr) {
        int n = arr.size();
        int count = 0; // Position to place the next non-zero element
        
        // Traverse the array
        for (int i = 0; i < n; i++) {
            if (arr[i] != 0) {
                arr[count++] = arr[i];
            }
        }
        
        // Fill remaining positions with zeroes
        while (count < n) {
            arr[count++] = 0;
        }
    }
};
