class Solution:
    def findFinalValue(self, nums: List[int], original: int) -> int:
        hash = defaultdict(int);
        for i in range(0,len(nums)):
            hash[nums[i]] += 1;
        
        while hash[original] > 0:
            original *= 2

        return original