class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        st1 = []
        st2 = []
        for i in s:
            if st1 and i == '#':
                st1.pop()
            elif i != '#':
                st1.append(i)
        
        for j in t:
            if st2 and j == '#':
                st2.pop()
            elif j != '#':
                st2.append(j)
        
        if "".join(st1) == "".join(st2):
            return True
        
        return False


sol = Solution()
#s = "ab#c"
#t = "ad#c"

#s = "a#c"
#t = "b"

s = "y#fo##f"
t = "y#f#o##f"

if sol.backspaceCompare(s, t):
    print("True")
else:
    print("False")
        
        