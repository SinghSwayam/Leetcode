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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodeMap;
        unordered_set<int> children;

        for(auto desc : descriptions){
            int parent = desc[0];
            int child = desc[1];
            bool isLeft = desc[2];

            if(nodeMap.find(parent) == nodeMap.end()){
                nodeMap[parent] = new TreeNode(parent);
            }
            TreeNode* parentNode = nodeMap[parent];


            if (nodeMap.find(child) == nodeMap.end()) {
                nodeMap[child] = new TreeNode(child);
            }
            TreeNode* childNode = nodeMap[child];

            if (isLeft) {
                parentNode->left = childNode;
            } else {
                parentNode->right = childNode;
            }

            children.insert(child);
        }
        for (auto desc : descriptions) {
            int parent = desc[0];
            if (children.find(parent) == children.end()) {
                return nodeMap[parent];
            }
        }

        return NULL; 
    }
};