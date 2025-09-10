class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        cache = {};
        def rec(i,j):
            if(j < 0): return 1;
            if(i < 0): return 0;
            
            if (i,j) in cache:
                return cache[(i,j)];
            if(s[i] == t[j]):
                cache[(i,j)] = rec(i-1,j-1) + rec(i-1,j);
            else: 
                cache[(i,j)] = rec(i-1,j);
            return cache[(i,j)];
        return rec(len(s)-1,len(t)-1);