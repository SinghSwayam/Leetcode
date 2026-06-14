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
    ListNode* reverseList(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL) {
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }

    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
    
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        slow->next = reverseList(slow->next);
        
        ListNode* temp1 = head;
        ListNode* temp2 = slow->next;
        int sum = 0;
        while(temp2){
            int currsum = temp1->val + temp2->val;
            sum = max(sum, currsum);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return sum;
    }
};