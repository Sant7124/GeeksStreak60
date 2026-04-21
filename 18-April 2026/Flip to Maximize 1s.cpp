class Solution {
public:
    int maxOnes(vector<int>& arr) {
        int totalOnes = 0;
        
        for (int x : arr) {
            if (x == 1) totalOnes++;
        }
        
        int maxSum = 0, currSum = 0;
        
        for (int x : arr) {
            int val = (x == 0) ? 1 : -1;
            
            currSum = max(val, currSum + val);
            maxSum = max(maxSum, currSum);
        }
        
        return totalOnes + maxSum;
    }
};
