class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
      long long sum1 = 0 , sum2 = 0 , i = 0;
      int zero1 = 0 , zero2 = 0;
      while(i < nums1.size() && i < nums2.size()){
        sum1 += nums1[i];
        sum2 += nums2[i];
        if(nums1[i] == 0){
            zero1++;
        }
        if(nums2[i] == 0){
            zero2++;
        }
        i++;
      }
      while(i < nums1.size()){
        sum1 += nums1[i];
        if(nums1[i] == 0){
            zero1++;
        }
        i++;
      }  
      while(i < nums2.size()){
        sum2 += nums2[i];
        if(nums2[i] == 0){
            zero2++;
        }
        i++;
      }
        cout << sum1 << endl;
        cout << sum2 << endl;
        cout << zero1 << endl;
        cout << zero2 << endl;
      long long diff = abs(sum1 - sum2);

      if(sum1 == sum2){
        if(zero1 == 0 ^ zero2 == 0) return -1;
        return sum1 + max(zero1 , zero2);
      }
      if(sum1 > sum2){
        if(zero2 == 0) return -1;
        if(zero1 == 0 && zero2 > diff) return -1;
        if(sum1 + zero1 < sum2 + zero2) { 
            return sum2 + zero2;
        }
        return sum1 + zero1;
      }

      if(zero1 == 0) return -1;
      if(zero2 == 0 && zero1 > diff) return -1;
      if(sum2 + zero2 < sum1 + zero1){
        return sum1 + zero1;
      }
      return sum2 + zero2;
    }
};