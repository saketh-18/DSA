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
#include <bits/stdc++.h>
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* ans = head;
        while(head != nullptr && head->next != nullptr){
            ListNode* temp = new ListNode(__gcd(head->val,head->next->val));
            ListNode* next  = head->next;
            head->next = temp;
            temp->next = next;
            head = head->next->next;
        }
        return ans;
    }
};