#include <bits/stdc++.h>
class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        //2 pointer

        int i = 1;
        vector<int> vec;
        vec.push_back(nums[0]);
        while(i < nums.size()){
            long long hcf = gcd(vec.back(),nums[i]);
            long long back = vec.back();
            long long cur = nums[i];
            long long lcm = (back / hcf) * cur;

            if(hcf > 1){
                vec[vec.size()-1] = (int)lcm;
            } else {
                vec.push_back(nums[i]);
            }
            
            while(vec.size() >= 2){
                long long hcf = gcd(vec.back(),vec[vec.size()-2]);
                long long back = vec.back();
                long long cur = vec[vec.size()-2];
                long long lcm = (back / hcf) * cur;

                if(hcf > 1){
                    vec[vec.size()-2] = (int)lcm;
                    vec.pop_back();
                } else break;
            }
            i++;
        }
        return vec;
    }
};