class Solution {
public:
    int derangeCount(int n) {
        if(n == 1) return 0;
        if(n == 2) return 1;

        int prev2 = 0; // D(1)
        int prev1 = 1; // D(2)
        int curr;

        for(int i = 3; i <= n; i++) {
            curr = (i - 1) * (prev1 + prev2);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};
