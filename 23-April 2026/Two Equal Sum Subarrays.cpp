class Solution {
public:
    bool canSplit(vector<int>& arr) {
        long long total = 0;
        
        // Step 1: Calculate total sum
        for (int x : arr) {
            total += x;
        }
        
        // Step 2: If odd, cannot split
        if (total % 2 != 0) return false;
        
        long long target = total / 2;
        long long prefix = 0;
        
        // Step 3: Find prefix sum = target
        for (int x : arr) {
            prefix += x;
            if (prefix == target) return true;
        }
        
        return false;
    }
};
