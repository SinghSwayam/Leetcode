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
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

        for(int i=0; i<lists.size(); i++){
            if(lists[i] != NULL){
                pq.push(lists[i]);
            }
        }

        ListNode* temp = new ListNode(0);
        ListNode* tail = temp;

        while(!pq.empty()){
            ListNode* frontNode = pq.top();
            pq.pop();

            tail->next = frontNode;
            tail = tail->next;

            if(frontNode->next != NULL){
                pq.push(frontNode->next);
            }
        }
        return temp->next;
    }
};