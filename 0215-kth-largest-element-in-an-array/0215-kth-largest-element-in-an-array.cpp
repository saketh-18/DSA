class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue < int, vector<int>, greater<int> > pq;
        for(int i : nums) pq.push(i);
        int i = 0;
        while( i < nums.size()- k) {
            pq.pop();
            i++;
        }
        return pq.top();
    }
};