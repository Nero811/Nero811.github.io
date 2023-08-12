class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        dic = {}
        dic2 = {}
        for i in range(len(s)):
            if dic.get(s[i]) and dic.get(s[i]) != t[i]:
                return False
            if dic2.get(t[i]) and dic2.get(t[i]) != s[i]:
                return False
            dic[s[i]] = t[i]
            dic2[t[i]] = s[i]

        return True


sol = Solution()
s = "badc"
t = "baba"
if sol.isIsomorphic(s, t):
    print("True")
else:
    print("False")
        
