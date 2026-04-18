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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next){
            return NULL;
        }

        ListNode* prevNode = NULL;
        ListNode* slow = head;
        ListNode* fast = head;

        while(slow != NULL && fast != NULL){
            fast = fast->next;
            if(fast != NULL){
                fast = fast->next;
                prevNode = slow;
                slow = slow->next;
            }
        }

        prevNode->next = slow->next;
        slow->next = NULL;

        return head;

    }
};