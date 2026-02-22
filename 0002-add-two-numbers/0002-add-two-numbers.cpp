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
    void insertAtTail(ListNode*& head, ListNode*& tail, int data){
        if (head == NULL && tail == NULL){
            ListNode* newNode = new ListNode(data);
            head = newNode;
            tail = newNode;
            return;
        }
        ListNode* newNode = new ListNode(data);
        tail->next = newNode;
        tail = newNode;
    }


    ListNode* solve(ListNode*& head1, ListNode*& head2) {
        //add : 
        ListNode* ansHead = NULL;
        ListNode* ansTail = NULL;
        int carry = 0;
        while (head1 != NULL && head2 != NULL) {
            int sum = carry + head1->val + head2->val;
            int digit = sum % 10;
            carry = sum / 10;
            insertAtTail(ansHead, ansTail, digit);
            head1 = head1->next;
            head2 = head2->next;
        }
        while (head1 != NULL) {
            int sum = carry + head1->val;
            int digit = sum % 10;
            carry = sum / 10;
            insertAtTail(ansHead, ansTail, digit);
            head1 = head1->next;
        }
        while (head2 != NULL) {
            int sum = carry + head2->val;
            int digit = sum % 10;
            carry = sum / 10;
            insertAtTail(ansHead, ansTail, digit);
            head2 = head2->next;
        }
        while (carry != 0) {
            int sum = carry;
            int digit = sum % 10;
            carry = sum / 10;
            insertAtTail(ansHead, ansTail, digit);
        }
        return ansHead;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        return solve(l1,l2);
    }
    
};