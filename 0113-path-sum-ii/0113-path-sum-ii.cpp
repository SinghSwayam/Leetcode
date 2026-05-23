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
    void solve(TreeNode*& root, int targetSum, vector<int>& currAns, vector<vector<int>>& ans){
        if(!root) return;

        currAns.push_back(root->val);
        if(!root->left && !root->right){
            if(targetSum == root->val){
                ans.push_back(currAns);
            }
        }
        
        solve(root->left, (targetSum - root->val), currAns, ans);
        solve(root->right, (targetSum - root->val), currAns, ans);
        
        currAns.pop_back(); 
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> currAns;
        vector<vector<int>> ans;
        solve(root, targetSum, currAns, ans);
        return ans;
    }
};