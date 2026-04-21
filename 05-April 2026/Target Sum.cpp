class Solution {
  public:
    int totalWays(vector<int>& arr, int target) {
        int n = arr.size();
        
        int sum = 0;
        for(int x : arr) sum += x;
        
        // Edge cases
        if(abs(target) > sum) return 0;
        if((target + sum) % 2 != 0) return 0;
        
        int s = (target + sum) / 2;
        
        vector<int> dp(s + 1, 0);
        dp[0] = 1;
        
        for(int i = 0; i < n; i++) {
            for(int j = s; j >= arr[i]; j--) {
                dp[j] += dp[j - arr[i]];
            }
        }
        
        return dp[s];
    }
};
