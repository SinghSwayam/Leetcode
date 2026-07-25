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
    ListNode* solve(ListNode* first, ListNode* second){
        if(!first || !second) return first;

        ListNode* forward = second->next;

        second->next = first;

        if(forward){
            first->next = solve(forward, forward->next);
        }else{
            first->next = NULL;
        }
        return second;
    }

    ListNode* swapPairs(ListNode* head) {
        if(!head) return NULL;
        if(!head->next) return head;

        return solve(head, head->next);
    }
};