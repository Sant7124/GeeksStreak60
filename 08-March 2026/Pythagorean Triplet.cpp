class Solution {
public:
    bool pythagoreanTriplet(vector<int>& arr) {
        int n = arr.size();
        
        unordered_set<int> s;
        
        // Store squares
        for(int i = 0; i < n; i++){
            s.insert(arr[i] * arr[i]);
        }
        
        // Check combinations
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int sum = arr[i]*arr[i] + arr[j]*arr[j];
                if(s.find(sum) != s.end()){
                    return true;
                }
            }
        }
        
        return false;
    }
};
