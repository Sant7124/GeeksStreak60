class Solution {
public:
    
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    
    int solve(int fromCap, int toCap, int d) {
        int from = 0, to = 0;
        int step = 0;
        
        while (from != d && to != d) {
            
            if (from == 0) {
                from = fromCap;
                step++;
            }
            
            int transfer = min(from, toCap - to);
            to += transfer;
            from -= transfer;
            step++;
            
            if (from == d || to == d)
                break;
            
            if (to == toCap) {
                to = 0;
                step++;
            }
        }
        
        return step;
    }
    
    int minSteps(int m, int n, int d) {
        
        // Edge cases
        if (d == 0) return 0;
        if (d == m || d == n) return 1;  // 🔥 FIX
        
        if (d > max(m, n)) return -1;
        if (d % gcd(m, n) != 0) return -1;
        
        return min(solve(m, n, d), solve(n, m, d));
    }
};
