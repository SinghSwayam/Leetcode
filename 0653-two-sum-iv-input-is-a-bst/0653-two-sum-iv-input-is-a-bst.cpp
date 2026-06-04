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
    void inorder(TreeNode* root, vector<int>& nums){
        if(!root) return;

        inorder(root->left,nums);
        nums.push_back(root->val);
        inorder(root->right,nums);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> nums;
        inorder(root,nums);

        int s = 0;
        int e = nums.size()-1;

        while(s < e){
            int sum = nums[s] + nums[e];
            if(sum == k){
                return true;
            }else if(sum > k){
                e--;
            }else{
                s++;
            }
        }
        return false;
    }
};