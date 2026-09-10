/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:
    // This function returns the actual height if the tree is balanced, 
    // or -1 if any part of the subtree is unbalanced.
    int checkHeight(TreeNode* root) {
        if (!root) return 0; // Base case: height of null node is 0

        // 1. Get the height of the left subtree
        int lh = checkHeight(root->left);
        if (lh == -1) return -1; // If left subtree is unbalanced, pass the error up

        // 2. Get the height of the right subtree
        int rh = checkHeight(root->right);
        if (rh == -1) return -1; // If right subtree is unbalanced, pass the error up

        // 3. Check if the current node is unbalanced
        if (abs(lh - rh) > 1) return -1;

        // 4. Return the actual height to the parent node
        return 1 + max(lh, rh);
    }
    
public:
    bool isBalanced(TreeNode* root) {
        // If the helper function returns -1, the tree is unbalanced.
        return checkHeight(root) != -1;
    }
};