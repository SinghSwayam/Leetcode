/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA = headA;
        ListNode* tempB = headB;

        while(tempA->next!=NULL && tempB->next!=NULL){
            if(tempA == tempB) return tempA;

            tempA = tempA->next;
            tempB = tempB->next;
        }

        if(tempA->next==NULL && tempB->next==NULL && headA!=headB) return NULL;

        int countA=0;
        int countB=0;
        if(tempA->next==NULL){
            while(tempB->next!=NULL){
                tempB = tempB->next;
                countB++;
            }
            while(countB--){
                headB = headB->next;
            }
        }else{
            while(tempA->next!=NULL){
                tempA = tempA->next;
                countA++;
            }
            while(countA--){
                headA = headA->next;
            }
        }

        while(headA!=headB){
            headA = headA->next;
            headB = headB->next;
        }
        return headA;



    }
};