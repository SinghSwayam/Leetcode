/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getLength(ListNode* head){
        int len=0;
        while(head!=NULL){
            head = head->next;
            len++;
        }
        return len;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = getLength(head);
        if(k > len){
            return head;
        }

        ListNode* left = NULL;
        ListNode* curr = head;
        ListNode* right = NULL;
        int count=0;

        while(count < k){
            right = curr->next;
            curr->next = left;
            left = curr;
            curr = right;
            count++;
        }

        if(right != NULL){
            head->next = reverseKGroup(right,k);
        }

        return left;
    }
};