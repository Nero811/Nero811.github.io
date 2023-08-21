from typing import List

class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        i = 0
        j = len(nums) - 1
        while i <= j:
            mid = (i + j)//2
            if target > nums[mid]:
                i = mid + 1
            elif target < nums[mid]:
                j = mid - 1
            else:
                return mid
        
        return mid + 1 if target > nums[mid] else mid

if __name__ == "__main__":
    sol = Solution()
    #nums = [1,3,5,6]
    nums = [1,3]
    target = 2
    print(sol.searchInsert(nums, target))