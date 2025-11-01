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
    // void delete(ListNode* prev){
    //     //prev->next = prev->next->next; if next->next exists 
    //     //prev->next = null; //if not exists

    //     if(prev->next->next){
    //         prev->next = prev->next->next;
    //     } else {
    //         prev->next = nullptr;
    //     }

    // }
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        //first hash all values in nums, then delete the that are present in nums and head
        unordered_map<int,int> hash;
    
        for(int i : nums){
            hash[i]++;
        }

        ListNode* prev = nullptr;
        ListNode* newHead = head;
        while(head){
            // cout << head->val << "first loop" << endl;
            if(hash.find(head->val) != hash.end()){
                head = head->next;
                newHead = head;
            } else break;
        }
        while(head->next){
            // cout << head->val << endl;
            if(hash.find(head->next->val) != hash.end()){
                if(head->next->next) head->next = head->next->next;
                else{
                    head->next = nullptr;
                }
            } else head = head->next;
        }
        return newHead;
    }
};