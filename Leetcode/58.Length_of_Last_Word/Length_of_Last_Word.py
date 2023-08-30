class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        end = len(s) - 1
        for i in range(len(s) - 1, -1, -1):
            if s[i] == ' ':
                end -= 1
            else:
                if end == 0:
                    return 1
                start = end
                while start > 0 and s[start] != ' ':
                    start -= 1
                return (end - start) + 1 if start == 0 and s[start] != ' ' else end - start
        
        return 0

if __name__ == "__main__":
    sol = Solution()
    #s = "Hello World"
    s = " a"
    print(sol.lengthOfLastWord(s))
                