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
    void solve(TreeNode*& root,vector<int>& curr,int& ans){
        if(!root) return;

        if(!root->left && !root->right){
            curr.push_back(root->val);
            int num = 0;
            for(int digit : curr){
                num = num * 10 + digit;
            }
            ans += num;
            curr.pop_back();
            return;
        }

        curr.push_back(root->val);
        solve(root->left,curr,ans);
        solve(root->right,curr,ans);
        curr.pop_back();
    }

    int sumNumbers(TreeNode* root) {
        int ans=0;
        vector<int> curr;
        solve(root,curr,ans);
        return ans;
    }
};