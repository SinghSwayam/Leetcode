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
        map<int, vector<int>> mp;
        queue<pair<TreeNode*, int>> q;

        q.push({root,0});

        while(!q.empty()){
            pair<TreeNode*, int> temp = q.front();
            q.pop();

            TreeNode* frontnode = temp.first;
            int lvl = temp.second;

            mp[lvl].push_back(frontnode->val);

            if(frontnode->left)
                q.push({frontnode->left,lvl - 1});
            
            if(frontnode->right)
                q.push({frontnode->right,lvl - 1});
        }

        for(auto i : mp){
            ans.push_back(i.second);
        }

        return ans;
    }
};