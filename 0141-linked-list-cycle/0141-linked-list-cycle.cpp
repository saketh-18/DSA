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
    bool hasCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr) return false;

        unordered_map<ListNode*,int> mpp;
        while(head != nullptr){
            if(mpp.find(head) == mpp.end()){
                mpp[head]++;
                head = head->next;
            }
            else return true;
        }
        return false;
    }
};