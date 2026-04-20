class Solution {
public:
    int moves = 0;
    
    int dfs(Node* root) {
        if (!root) return 0;
        
        int left = dfs(root->left);
        int right = dfs(root->right);
        
        moves += abs(left) + abs(right);
        
        return root->data + left + right - 1;
    }
    
    int distCandy(Node* root) {   // ✅ FIXED NAME
        moves = 0;                // reset for safety
        dfs(root);
        return moves;
    }
};
