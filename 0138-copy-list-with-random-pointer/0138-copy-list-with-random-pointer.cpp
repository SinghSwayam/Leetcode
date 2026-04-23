/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;

        Node* it = head;
        while(it){
            Node* clone_node = new Node(it->val);
            clone_node->next = it->next;
            it->next = clone_node;
            it = it->next->next;
        }

        it=head;
        while(it){
            Node* clone_node = it->next;
            clone_node->random = it->random ? it->random->next : NULL;
            it = it->next->next;
        }

        it = head;
        Node* clone_head = it->next;
        while(it){
            Node* temp = it->next;
            it->next = temp->next;
            if(temp->next){
                temp->next = temp->next->next;
            }

            it = it->next;
        }

        return clone_head;
    }
};