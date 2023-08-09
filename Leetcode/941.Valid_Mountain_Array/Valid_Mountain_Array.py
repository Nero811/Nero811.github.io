from typing import List

class Solution:
    def validMountainArray(self, arr: List[int]) -> bool:
        i = 1
        mountain = False
        pre = 0
        while i < len(arr):
            cur = arr[i] - arr[i - 1] 
            if cur == 0:
                return False
            elif i >= 2 and cur < 0 and pre > 0:
                mountain = True
            elif i >= 2 and cur > 0 and pre < 0:
                return False
            i += 1
            pre = cur

        return mountain

sol = Solution()
#arr = [0, 2, 3, 4, 5, 2, 1, 0]
arr = [0,1,2,3,4,8,9,10,11,12,11]
#arr = [3, 5, 5]
if sol.validMountainArray(arr):
    print("True")
else:
    print("False")
