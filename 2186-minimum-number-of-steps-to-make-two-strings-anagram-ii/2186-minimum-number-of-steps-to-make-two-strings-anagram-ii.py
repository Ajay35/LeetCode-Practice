class Solution:
    def minSteps(self, s: str, t: str) -> int:
        countS = collections.Counter(s)
        countT = collections.Counter(t)
        
        res = 0
        
        for letter in countS:
            res += max(0, countS[letter] - countT[letter])
        
        for letter in countT:
            res += max(0, countT[letter] - countS[letter])
        
        return res