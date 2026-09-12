class Solution {
private:
    int solve(TreeNode* root, int maxi) {

        if (!root) {
            return 0;
        }

        int good = 0;

        if (root->val >= maxi) {
            good = 1;
        }

        maxi = max(maxi, root->val);

        good += solve(root->left, maxi);
        good += solve(root->right, maxi);

        return good;
    }

public:
    int goodNodes(TreeNode* root) {

        if (!root) {
            return 0;
        }

        return solve(root, root->val);
    }
};