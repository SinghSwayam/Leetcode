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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummySmall = new ListNode(0);
        ListNode* dummyLarge = new ListNode(0);

        ListNode* small = dummySmall;
        ListNode* large = dummyLarge;
        ListNode* temp = head;
        while(temp){
            if(temp->val < x){
                small->next = temp;
                small = small->next;
            }else{
                large->next = temp;
                large = large->next;
            }

            temp = temp->next;
        }

        small->next = dummyLarge->next;
        large->next = NULL;

        return dummySmall->next;
    }
};