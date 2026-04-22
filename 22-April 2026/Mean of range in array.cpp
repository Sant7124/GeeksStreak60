class Solution {
public:
    vector<int> findMean(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        
        // Step 1: Build prefix sum
        vector<long long> prefix(n);
        prefix[0] = arr[0];
        
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + arr[i];
        }
        
        // Step 2: Process queries
        vector<int> result;
        
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            
            long long sum;
            if (l == 0)
                sum = prefix[r];
            else
                sum = prefix[r] - prefix[l - 1];
            
            int length = r - l + 1;
            
            result.push_back(sum / length); // floor automatically
        }
        
        return result;
    }
};
