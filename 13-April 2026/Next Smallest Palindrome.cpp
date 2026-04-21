class Solution{
public:
    vector<int> nextPalindrome(vector<int> &num) {
        
        int n = num.size();
        vector<int> res = num;
        
        // Step 1: Check if all 9s
        bool all9 = true;
        for(int i = 0; i < n; i++) {
            if(num[i] != 9) {
                all9 = false;
                break;
            }
        }
        
        if(all9) {
            vector<int> ans(n + 1, 0);
            ans[0] = 1;
            ans[n] = 1;
            return ans;
        }
        
        int mid = n / 2;
        int i = mid - 1;
        int j = (n % 2) ? mid + 1 : mid;
        
        bool leftSmaller = false;
        
        // Check left < right
        while(i >= 0 && res[i] == res[j]) {
            i--;
            j++;
        }
        
        if(i < 0 || res[i] < res[j]) {
            leftSmaller = true;
        }
        
        // Mirror
        while(i >= 0) {
            res[j] = res[i];
            i--;
            j++;
        }
        
        // Handle carry
        if(leftSmaller) {
            int carry = 1;
            i = mid - 1;
            
            if(n % 2 == 1) {
                res[mid] += carry;
                carry = res[mid] / 10;
                res[mid] %= 10;
                j = mid + 1;
            } else {
                j = mid;
            }
            
            while(i >= 0 && carry) {
                res[i] += carry;
                carry = res[i] / 10;
                res[i] %= 10;
                res[j] = res[i];
                i--;
                j++;
            }
        }
        
        return res;
    }
};
