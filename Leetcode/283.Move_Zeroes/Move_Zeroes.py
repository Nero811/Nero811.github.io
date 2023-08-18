from typing import List

class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        slowIdx = 0
        for fastIdx in range(len(nums)):
            if nums[fastIdx] == 0:
                continue
            nums[slowIdx] = nums[fastIdx]
            slowIdx += 1
        for index in range(slowIdx, len(nums)):
            nums[index] = 0


if __name__ == "__main__":
    sol = Solution()
    nums = [0,1,0,3,12]
    sol.moveZeroes(nums)
    print(nums)
