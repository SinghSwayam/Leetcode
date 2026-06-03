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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()){
            int n = q.size();
            vector<int> lvl;

            for(int i=0;i<n;i++){
                TreeNode* frontnode = q.front();
                q.pop();

                lvl.push_back(frontnode->val);

                if(frontnode->left)
                    q.push(frontnode->left);
                if(frontnode->right)
                    q.push(frontnode->right);
            }
            ans.push_back(lvl);
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};