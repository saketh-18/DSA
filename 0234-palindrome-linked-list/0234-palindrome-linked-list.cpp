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
    bool isPalindrome(ListNode* head) {
        vector<int> vec;
        vector<int> a;

        while(head -> next != NULL) {
            vec.push_back(head -> val);
            a.push_back(head -> val);
            head = head -> next;
        }

        if(head != NULL) {
            a.push_back(head -> val);
            vec.push_back(head -> val); 
        }

        reverse(vec.begin() , vec.end());

        int c = 0;
        for(int i = 0; i < vec.size(); i++){
            if(a[i] != vec[i]){
                c++;
            }
        }

        if(c > 0) {
            return false;
        }
        else {
            return true;
        }
    }
};