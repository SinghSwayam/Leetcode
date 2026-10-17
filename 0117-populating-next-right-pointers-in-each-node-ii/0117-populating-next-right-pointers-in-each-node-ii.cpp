/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;

        Node* curr = root;
        while(curr != NULL){
            Node* nextStart = NULL;
            Node* prev = NULL;

            while(curr != NULL){
                if(curr->left){
                    if (prev) {
                        prev->next = curr->left;
                    } else {
                        nextStart = curr->left;
                    }
                    prev = curr->left;
                }

                if(curr->right){
                    if (prev) {
                        prev->next = curr->right;
                    } else {
                        nextStart = curr->right;
                    }
                    prev = curr->right;
                }

                curr = curr->next;
            }
            curr = nextStart;
        }
        return root;
    }
};