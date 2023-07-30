

class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        next = [0] * len(s)
        j = 0
        next.append(j)
        for i in range(1,len(s)):
            while j > 0 and s[i] != s[j]:
                j = next[j - 1]
            if s[i] == s[j]:
                j += 1
            next[i] = j
        if len(s) % (len(s) - next[len(s) - 1]) == 0 and next[len(s) - 1] > 0:
            return True

sol = Solution()
#s = "abab"
s = "aba"
print("True") if sol.repeatedSubstringPattern(s) else print("False")