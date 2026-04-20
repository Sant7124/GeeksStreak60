class Solution {
public:
    
    int countBST(vector<int>& nodes) {
        int n = nodes.size();
        if (n <= 1) return 1;
        
        int total = 0;
        
        for (int i = 0; i < n; i++) {
            int root = nodes[i];
            
            vector<int> left, right;
            
            for (int j = 0; j < n; j++) {
                if (j == i) continue;
                if (nodes[j] < root) left.push_back(nodes[j]);
                else right.push_back(nodes[j]);
            }
            
            int leftCount = countBST(left);
            int rightCount = countBST(right);
            
            total += (leftCount * rightCount);
        }
        
        return total;
    }
    
    // 🔥 Function name must be EXACTLY this
    vector<int> countBSTs(vector<int>& arr) {
        int n = arr.size();
        vector<int> result;
        
        for (int i = 0; i < n; i++) {
            int root = arr[i];
            
            vector<int> left, right;
            
            for (int j = 0; j < n; j++) {
                if (j == i) continue;
                if (arr[j] < root) left.push_back(arr[j]);
                else right.push_back(arr[j]);
            }
            
            int leftCount = countBST(left);
            int rightCount = countBST(right);
            
            result.push_back(leftCount * rightCount);
        }
        
        return result;
    }
};
