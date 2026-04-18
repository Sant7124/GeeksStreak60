#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size();
        
        // Step 1: Transform array
        for (int i = 0; i < n; i++) {
            arr[i] = (arr[i] > k) ? 1 : -1;
        }
        
        // Step 2: Prefix sums
        vector<int> prefix(n+1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i+1] = prefix[i] + arr[i];
        }
        
        // Step 3: Build decreasing stack of prefix indices
        vector<int> stack;
        for (int i = 0; i <= n; i++) {
            if (stack.empty() || prefix[i] < prefix[stack.back()]) {
                stack.push_back(i);
            }
        }
        
        // Step 4: Traverse from end to start
        int ans = 0;
        for (int i = n; i >= 0; i--) {
            while (!stack.empty() && prefix[i] > prefix[stack.back()]) {
                ans = max(ans, i - stack.back());
                stack.pop_back();
            }
        }
        
        return ans;
    }
};
