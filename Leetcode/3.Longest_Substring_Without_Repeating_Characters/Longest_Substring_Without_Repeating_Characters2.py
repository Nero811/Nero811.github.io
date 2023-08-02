class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        dic = {}
        if len(s) == 1:
            return 1
        subString = ""
        result = 0
        j = 0
        for i in range(len(s)):
            if s[i] in dic.keys():
                dic.clear()
                while s[j] != s[i]:
                    j += 1
                while j < i and s[j] == s[i]:
                    j += 1
                for k in range(j, i + 1):
                    dic[s[k]] = 1
                subString = s[j:i + 1]
            else:
                dic[s[i]] = 1
                subString = s[j:i + 1]
            result = max(result, len(subString))
        return result

#s = "abcabcbb"
#s = "pwwkew"
#s = "dvdf"
#s = "au"
s = "tmmzuxt"
sol = Solution()
print(sol.lengthOfLongestSubstring(s))
