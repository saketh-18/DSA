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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }

        ListNode* temp = head;
        ListNode* oldHead = head;
        int count = 1;
        while(head->next != nullptr){
            head = head->next;
            count++;
        }  

        for(int i = 1; i < count - k%count; i++){
            temp = temp->next;
        }

        head->next = oldHead;
        ListNode* newHead = temp->next;
        temp->next = nullptr;
        return newHead;
    }
};