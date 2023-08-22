from typing import List

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        slowIdx = 0
        result = 1
        for fastIdx in range(len(nums)):
            if nums[fastIdx] != nums[slowIdx]:
                slowIdx = fastIdx
                nums[result] = nums[slowIdx]
                result += 1
        
        return result


if __name__ == "__main__":
    sol = Solution()
    nums = [0,0,1,1,1,2,2,3,3,4]
    print(sol.removeDuplicates(nums))
    