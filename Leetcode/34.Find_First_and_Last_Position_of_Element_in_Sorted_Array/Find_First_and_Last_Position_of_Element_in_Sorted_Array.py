from typing import List

class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        i = 0
        j = len(nums) - 1
        result = []
        while i <= j:
            mid = (i + j) // 2
            if nums[mid] < target:
                i = mid + 1
            elif nums[mid] > target:
                j = mid - 1
            else:
                startIdx = mid
                endIdx = mid
                while startIdx >= 0 and nums[startIdx] == target:
                    startIdx -= 1
                while endIdx <= len(nums) - 1 and nums[endIdx] == target:
                    endIdx += 1
                return [startIdx + 1, endIdx - 1]
        
        return [-1, -1]


if __name__ == "__main__":
    sol = Solution()
    nums = [5,7,7,8,8,10]
    target = 6
    print(sol.searchRange(nums, target))