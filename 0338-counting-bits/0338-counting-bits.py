class Solution(object):
    def countBits(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        ans = [];
        for i in range(0,n+1):
            bs = format(i,"b");
            ans.append(bs.count('1'));

        return ans;
        