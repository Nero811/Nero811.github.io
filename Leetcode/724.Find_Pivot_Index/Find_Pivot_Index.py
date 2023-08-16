from typing import List

class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        pivot = 0
        left = 0
        right = 0
        for i in range(1,len(nums)):
            right += nums[i]

        while pivot < len(nums):
            if left != right:
                left += nums[pivot]
                pivot += 1
                if pivot <= len(nums) - 1:
                    right -= nums[pivot]
            else:
                return pivot
        
        return -1

sol = Solution()
#nums = [1,7,3,6,5,6]
#nums = [1,2,3]
nums = [2,1,-1]
print(sol.pivotIndex(nums))