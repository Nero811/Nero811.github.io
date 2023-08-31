class Solution:
    def balancedStringSplit(self, s: str) -> int:
        count = 0
        result = 0
        for char in s:
            if char == 'R':
                count += 1
            else:
                count -= 1
            
            if count == 0:
                result += 1
        
        return result
    

if __name__== "__main__":
    s = "RLRRLLRLRL"
    sol = Solution()
    print(sol.balancedStringSplit(s))
            