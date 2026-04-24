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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1,-1}; // min ,max distance
        ListNode* left = head;
        if(!left) return ans;
        ListNode* curr = head->next;
        if(!curr) return ans;
        ListNode* right = head->next->next;
        if(!right) return ans;

        int firstCP = -1;
        int lastCP = -1;
        int minDist = INT_MAX;
        int i = 1;

        while(right){
            bool isCP = ( (curr->val > left->val && curr->val > right->val) || 
                          (curr->val < left->val && curr->val < right->val) ) ? true : false;

            if(isCP && firstCP == -1){
                firstCP = i;
                lastCP = i;
            }else if(isCP){
                minDist = min(minDist,(i - lastCP));
                lastCP = i;
            }
            ++i;
            left = left->next;
            curr = curr->next;
            right = right->next;
        }

        if(lastCP == firstCP){
            return ans;
        }else{
            ans[0] = minDist;
            ans[1] = lastCP - firstCP;
        }
        
        return ans;
    }
};