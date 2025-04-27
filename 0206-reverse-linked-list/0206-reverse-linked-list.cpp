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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr){
            return nullptr;
        }
        if(head->next == nullptr){
            return head;
        }

        vector<int> vec;
        
        ListNode* temp = head;
        ListNode* ans = head;

        while(temp->next != nullptr){
            vec.push_back(temp->val);
            temp = temp->next;
        }
        vec.push_back(temp->val);

        for(int i = 0 ; i < vec.size(); i++){
            cout << vec[i];        
        }
        
        for(int i = vec.size()-1; i >= 0; i--){
            head->val = vec[i];
            head = head->next;
        }

        return ans;
    }
};