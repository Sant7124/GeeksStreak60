class Solution {
public:
    long long countIncreasing(vector<int>& arr) {
        int n = arr.size();
        long long ans = 0;
        
        int len = 1;
        
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i - 1]) {
                len++;
                ans += (len - 1);
            } else {
                len = 1;
            }
        }
        
        return ans;
    }
};
