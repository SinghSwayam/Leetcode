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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;

        ListNode* ans = new ListNode(-1);
        ListNode* tailPtr = ans;

        while(list1!=NULL && list2!=NULL){
            if(list1->val <= list2->val){
                ListNode* curr = list1;
                list1 = list1->next;
                tailPtr->next = curr;
                tailPtr = curr;
            }else{
                ListNode* curr = list2;
                list2 = list2->next;
                tailPtr->next = curr;
                tailPtr = curr;
            }
        }

        if(list1!=NULL){
            tailPtr->next = list1;
        }else{
            tailPtr->next = list2;
        }

        return ans->next;
        
    }
};