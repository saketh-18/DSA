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
    ListNode* sortList(ListNode* head) {
        if(head == nullptr) return nullptr;
        if(head->next == nullptr) return head;
        ListNode* temp = head;
        ListNode* temp2 = head;
        vector<int> vec;
        while(temp != nullptr){
            vec.push_back(temp->val);
            temp = temp->next;
        }
        sort(vec.begin() , vec.end());
        for(auto i : vec){
            temp2->val = i;
            temp2 = temp2->next;
        }
        return head;
    }
};