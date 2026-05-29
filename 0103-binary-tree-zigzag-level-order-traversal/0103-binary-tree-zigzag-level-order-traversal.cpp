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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};

        vector<vector<int>> ans;
        bool LtoR = true;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int width = q.size();
            vector<int> currlvl(width);
            for(int i=0;i<width;i++){
                int index = LtoR ? i : (width - i - 1);
                TreeNode* frontnode = q.front(); q.pop();
                currlvl[index] = frontnode->val;

                if(frontnode->left){
                    q.push(frontnode->left);
                }

                if(frontnode->right){
                    q.push(frontnode->right);
                }
            }
            LtoR = !LtoR;
            ans.push_back(currlvl);
        }
        return ans;
    }
};