class Solution:
    def isLongPressedName(self, name: str, typed: str) -> bool:
        lt = [0] * 26
        for word in name:
            lt[ord(word) - ord('a')] += 1

        j = 0
        i = 0
        while i < len(name):
            if  j > len(typed) - 1 or name[i] != typed[j]:
                return False
            while j < len(typed) and i < len(name) and name[i] == typed[j]:
                lt[ord(name[i]) - ord('a')] -= 1
                j += 1
                if i + 1 < len(name) and j < len(typed) and name[i] == name[i + 1] and typed[j] == name[i + 1]:
                    i += 1

            if j >= len(typed) - 1 and typed[-1] != name[-1]:
                return False
            i += 1
            
        if j < len(typed) - 1:
            return False

        for num in lt:
            if num > 0:
                return False
        
        return True

sol = Solution()
name = "kpufanyrqqmtgxhyycltlnusyeyyqygwupcaagtkuqkwamvdsi"
typed = "kpuufaanyrqqqmttggxxhyyyycclttllnusyeyqqyggwuuppccaaaggtkkuuqkwwamvvddsii"
if sol.isLongPressedName(name, typed):
    print("True")
else:
    print("False")