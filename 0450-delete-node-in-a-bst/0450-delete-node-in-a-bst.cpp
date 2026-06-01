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
    int findMax(TreeNode* root){
        if(!root) return INT_MIN;

        while(root->right){
            root = root->right;
        }
        return root->val;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;

        if(root->val == key){
            if(!root->left && !root->right){
                delete root;
                return NULL;
            }else if(!root->left && root->right){
                TreeNode* child = root->right;
                delete root;
                return child;
            }else if(root->left && !root->right){
                TreeNode* child = root->left;
                delete root;
                return child;
            }else{
                int maxChildInLeft = findMax(root->left);
                root->val = maxChildInLeft;
                root->left = deleteNode(root->left,maxChildInLeft);
            }
        }else if(key > root->val){
            root->right =  deleteNode(root->right,key);
        }else{
            root->left = deleteNode(root->left,key);
        }

        return root;
    }
};