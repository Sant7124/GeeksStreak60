class Solution {
public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        int n = arr.size();
        
        int curr_xor = 0;
        
        // First window
        for (int i = 0; i < k; i++) {
            curr_xor ^= arr[i];
        }
        
        int max_xor = curr_xor;
        
        // Sliding window
        for (int i = k; i < n; i++) {
            curr_xor ^= arr[i - k]; // remove
            curr_xor ^= arr[i];     // add
            
            max_xor = max(max_xor, curr_xor);
        }
        
        return max_xor;
    }
};
