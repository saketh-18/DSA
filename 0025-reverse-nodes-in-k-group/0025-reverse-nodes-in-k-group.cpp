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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevGroupTail = &dummy;
        ListNode* temp = head;

        while (true) {
            // Check if there are at least k nodes ahead
            ListNode* check = temp;
            for (int i = 0; i < k; i++) {
                if (!check) return dummy.next;
                check = check->next;
            }

            // Reverse k nodes
            ListNode* run = temp;
            ListNode* prev = check;
            for (int i = 0; i < k; i++) {
                ListNode* nextNode = run->next;
                run->next = prev;
                prev = run;
                run = nextNode;
            }

            // Connect previous group to current reversed head
            prevGroupTail->next = prev;

            // Move prevGroupTail to temp (which is the tail after reverse)
            prevGroupTail = temp;
            temp = check;
        }

        return dummy.next;
    }
};



