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
    void createMap(vector<int>& inorder,unordered_map<int,int>& mp,int& size){
        for(int i=0;i<size;i++){
            mp[inorder[i]] = i;
        }
    }

    TreeNode* buildTreeFromInorderAndPostorder(vector<int>& postorder, vector<int>& inorder,unordered_map<int,int>& mp, int& size, int& postIndex, int inStart, int inEnd){
        if(postIndex < 0 || inStart > inEnd){
            return NULL;
        }

        int element = postorder[postIndex--];
        TreeNode* root = new TreeNode(element);
        int position = mp[element];

        root->right = buildTreeFromInorderAndPostorder(postorder,inorder,mp,size,postIndex,position+1,inEnd);

        root->left = buildTreeFromInorderAndPostorder(postorder,inorder,mp,size,postIndex,inStart,position-1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = inorder.size();
        int postIndex = size-1;
        int inStart = 0;
        int inEnd = size-1;
        unordered_map<int,int> mp;
        createMap(inorder,mp,size);

        return buildTreeFromInorderAndPostorder(postorder,inorder,mp,size,postIndex,inStart,inEnd);
    }
};