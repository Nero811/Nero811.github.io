class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        lt1 = [0] * 127
        lt2 = [0] * 127
        dic = {}
        for i in range(len(s)):
            lt1[ord(s[i])] += 1
            lt2[ord(t[i])] += 1
            if len(dic) > 0 and dic.get(s[i]) and dic.get(s[i]) and dic.get(s[i]) != t[i]:
                return False
            dic[s[i]] = t[i]

        for k in range(len(s)):
            if lt1[ord(s[k])] != lt2[ord(t[k])]:
                return False


        return True


sol = Solution()
s = "badc"
t = "baba"
if sol.isIsomorphic(s, t):
    print("True")
else:
    print("False")
        
