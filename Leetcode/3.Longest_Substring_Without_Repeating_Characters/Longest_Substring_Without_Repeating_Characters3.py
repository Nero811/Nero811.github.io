class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        lt = [0] * 128
        result = 0
        j = 0
        for i in range(len(s)):
            j = max(lt[ord(s[i])], j)
            result = max(result, (i - j) + 1)
            lt[ord(s[i])] = i + 1
        return result

#s = "abcabcbb"
s = "pwwkew"
#s = "dvdf"
#s = "au"
#s = "tmmzuxt"
sol = Solution()
print(sol.lengthOfLongestSubstring(s))
