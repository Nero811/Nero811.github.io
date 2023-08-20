from typing import List

class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        while k > 0:
            recodeList = nums.copy()
            j = 1
            for i in range(len(recodeList) - 1):
                nums[j] = recodeList[i]
                j += 1
                
            nums[0] = recodeList[-1]
            k -= 1

if __name__ == "__main__":
    sol = Solution()
    #nums = [1,2,3,4,5,6,7]
    #k = 3
    nums = [-1,-100,3,99]
    k = 2
    sol.rotate(nums, k)
    print(nums)
