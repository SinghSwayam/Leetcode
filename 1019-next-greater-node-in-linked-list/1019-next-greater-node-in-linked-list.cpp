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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> arr;
        while(head){
            arr.push_back(head->val);
            head=head->next;
        }

        int size = arr.size();
        vector<int> ans(size);
        stack<int> st;
        st.push(INT_MAX);
        
        for(int i=size-1;i>=0;i--){
            int curr = arr[i];
            while(st.top() <= curr){
                st.pop();
            }
            ans[i] = st.top() == INT_MAX ? 0 : st.top();
            st.push(curr);
        }

        return ans;
        
    }
};