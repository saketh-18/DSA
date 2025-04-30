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
    void reorderList(ListNode* head) {
        if(!head || !head->next) return; 
        ListNode* count = head;
        int num = 0;
        stack<ListNode*> st;
        while(count != nullptr){
            if(count){
                st.push(count);
            }
            count = count->next;
            num++;
        }
        int i = 1;
        while(i < num){
            count = head->next;
            head->next = st.top();
            st.pop();
            head = head->next;
            i++;
            // i < num ? head->next = count : bk;
            if(i < num && head != nullptr){
                head->next = count;
                head = head->next;
                i++;
            }   
            else {
                head->next = nullptr;
            }
        }
        if(head) head->next = nullptr;
    }
};