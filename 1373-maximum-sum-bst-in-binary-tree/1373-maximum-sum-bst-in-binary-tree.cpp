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
class NodeData{
    public:
    int sum;
    int minVal;
    int maxVal;
    bool isBST;

    NodeData(){}

    NodeData(int sum, int min,int max,bool bst){
        this->sum = sum;
        this->minVal = min;
        this->maxVal = max;
        this->isBST = bst;
    }
};

class Solution {
public:
    NodeData solve(TreeNode* root,int& ans){
        if(!root){
            return NodeData(0,INT_MAX,INT_MIN,true);
        }

        NodeData leftans = solve(root->left,ans);
        NodeData rightans = solve(root->right,ans);

        NodeData currans(0,INT_MAX,INT_MIN,false);

        if(leftans.isBST && 
           rightans.isBST && 
           root->val > leftans.maxVal && 
           root->val < rightans.minVal){
            int currSum = leftans.sum + rightans.sum + root->val;
            ans = max(ans,currSum);
            
            currans.sum = currSum;
            currans.minVal = min(root->val,leftans.minVal);
            currans.maxVal = max(root->val,rightans.maxVal);
            currans.isBST = true;
        }
        return currans;
    }

    int maxSumBST(TreeNode* root) {
        int ans = 0;
        solve(root,ans);
        return ans;
    }
};