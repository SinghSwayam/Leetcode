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
    int getLen(ListNode*& head){
        ListNode* temp = head;
        int count = 0;
        while(temp){
            temp = temp->next;
            count++;
        }
        return count;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return NULL;

        int len = getLen(head);
        int actualRotate = k % len;
        if(actualRotate == 0) return head;

        int newLastNodePos = len - actualRotate - 1;
        ListNode* newLastNode = head;
        for(int i=0;i<newLastNodePos;i++){
            newLastNode = newLastNode->next;
        } 
        ListNode* newHead = newLastNode->next;
        newLastNode->next = NULL;

        ListNode* it = newHead;
        while(it->next){
            it = it->next;
        }
        it->next = head;

        return newHead;

    }
};