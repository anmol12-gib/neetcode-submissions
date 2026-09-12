#include <bits/stdc++.h>
using namespace std;
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
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;

        vector<vector<int>> temp;

        if (!root) {
            return {};
        }

        queue<TreeNode*> q;
        q.push(root);

        

        while(!q.empty()){
            int sz=q.size();
            

            vector<int>level;
            while(sz--){

                TreeNode* node=q.front();
            q.pop();
                level.push_back(node->val);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }

            
            }

            temp.push_back(level);
        }

        for(int i=0;i<temp.size();i++){
            ans.push_back(temp[i][temp[i].size()-1]);
        }

        return ans;

        
        
    }
};
