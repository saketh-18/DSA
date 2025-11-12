class Solution:
    def minOperations(self, nums: List[int]) -> int:
        # check if there are any ones in the array
        one_count = 0;
        for i in range(0,len(nums)):
            if nums[i] == 1:
                one_count += 1;
        if one_count >= 1:
            return len(nums) - one_count;

        
        def gcd(a,b):
            while a and b:
                a = a % b;
                a , b = b , a;
            
            return max(a,b);    

        
        # check if any subarray equals to 1
        min_len = float("inf");
    
        for l in range(0,len(nums)):
            cur_gcd = 0
            for r in range(l,len(nums)):
                if r - l + 1 >= min_len:
                    break;
                cur_gcd = gcd(cur_gcd, nums[r]);
                if cur_gcd == 1:
                    min_len = r - l + 1;
                    break;

        if min_len == float("inf"):
            return -1;
        return (min_len - 1) + len(nums) - 1;