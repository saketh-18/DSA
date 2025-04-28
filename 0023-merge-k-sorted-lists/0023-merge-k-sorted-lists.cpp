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
    ListNode* helper(ListNode* list1, ListNode* list2) {
        ListNode* left = list1;
        ListNode* right = list2;
        ListNode* dummy = new ListNode(0);
        ListNode* head = dummy;
        while (left != nullptr && right != nullptr) {
            if (left->val <= right->val) {
                dummy->next = left;
                dummy = dummy->next;
                left = left->next;
            } else {
                dummy->next = right;
                dummy = dummy->next;
                right = right->next;
            }
        }

        dummy->next = left ? left : right;
        return head->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* merged = nullptr;

        for(int i = 0 ; i < lists.size(); i++){
            merged = helper(merged , lists[i]);
        }

        return merged;
    }
};