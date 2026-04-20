class Solution {
public:
    int maxProfit(vector<int>& arr, int k) {
        int n = arr.size();
        
        int hold = -arr[0];  // buying on first day
        int cash = 0;        // no stock
        
        for(int i = 1; i < n; i++) {
            hold = max(hold, cash - arr[i]);              // buy
            cash = max(cash, hold + arr[i] - k);          // sell
        }
        
        return cash;
    }
};
