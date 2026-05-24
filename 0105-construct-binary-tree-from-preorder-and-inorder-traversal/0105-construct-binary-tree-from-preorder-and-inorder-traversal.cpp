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
    int findPosition(vector<int>& arr,int& size, int& element){
        for(int i=0;i<size;i++){
            if(arr[i] == element)
                return i;
        }
        return -1;
    }

    TreeNode* buildTreeFromInorderAndPreorder(vector<int>& preorder, vector<int>& inorder, int& size, int& preIndex, int inStart, int inEnd){
        if(preIndex >= size || inStart > inEnd){
            return NULL;
        }

        int element = preorder[preIndex++];
        TreeNode* root = new TreeNode(element);
        int position = findPosition(inorder,size,element);

        root->left = buildTreeFromInorderAndPreorder(preorder,inorder,size,preIndex,inStart,position-1);
        root->right = buildTreeFromInorderAndPreorder(preorder,inorder,size,preIndex,position+1,inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = inorder.size();
        int preIndex = 0;
        int inStart = 0;
        int inEnd = size-1;

        TreeNode* tree = buildTreeFromInorderAndPreorder(preorder,inorder,size,preIndex,inStart,inEnd);
        return tree;
    }
};