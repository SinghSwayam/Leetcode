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
    bool solve(TreeNode* root, long long int lb, long long int ub){
        if(!root) return true;

        if(root->val > lb && root->val < ub){
            bool left = solve(root->left,lb,root->val);
            bool right = solve(root->right,root->val,ub);
            return left && right;
        }
        return false;
    }

    bool isValidBST(TreeNode* root) {
        long long int lb = LLONG_MIN;
        long long int ub = LLONG_MAX;
        return solve(root, lb, ub);
    }
};