class Solution {
private:
    void preorder(TreeNode* node, string& temp) {
        if(!node) {
            temp += '#';
            return;
        }

        temp += to_string(node->val);
        temp += '#';

        preorder(node->left, temp);
        preorder(node->right, temp);
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        string temp1 = "";
        string temp2 = "";

        preorder(root, temp1);
        preorder(subRoot, temp2);

        for(int i = 0; i < temp1.size(); i++) {

            for(int j = i; j < temp1.size(); j++) {

                string s1 = temp1.substr(i, j - i + 1);

                if(s1 == temp2) {
                    return true;
                }
            }
        }

        return false;
    }
};