class Solution {
private:
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,
                    int preStart, int preEnd,
                    int inStart, int inEnd) {

        if (preStart > preEnd || inStart > inEnd)
            return nullptr;

        // First element of preorder is the root
        TreeNode* root = new TreeNode(preorder[preStart]);

        // Find root in inorder
        int pos = inStart;
        while (inorder[pos] != root->val)
            pos++;

        // Number of elements in left subtree
        int leftSize = pos - inStart;

        // Build left subtree
        root->left = solve(preorder, inorder,
                           preStart + 1,
                           preStart + leftSize,
                           inStart,
                           pos - 1);

        // Build right subtree
        root->right = solve(preorder, inorder,
                            preStart + leftSize + 1,
                            preEnd,
                            pos + 1,
                            inEnd);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();

        return solve(preorder, inorder,
                     0, n - 1,
                     0, n - 1);
    }
};