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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;

        ListNode* dummyHead = new ListNode(-1);
        ListNode* dummyTail = dummyHead;
        ListNode* curr = head;

        while(curr != NULL){
            if(curr->next!=NULL && curr->val == curr->next->val){
                int num = curr->val;
                while(curr!=NULL && curr->val == num){
                    curr = curr->next;
                }
            }else{
                dummyTail->next = curr;
                dummyTail = curr;
                curr = curr->next;
                dummyTail->next = NULL;
            }
        }
        return dummyHead->next;
    }
};