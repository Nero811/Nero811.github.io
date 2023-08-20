from typing import List

class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        size = len(nums)
        while size - k < 0: # 扣除每一輪
            k -= size
        
        startIdx = size - k # 計算開始的index
        recodeList = nums.copy()
        j = 0
        for i in range(startIdx, len(recodeList)): # 開始的index到結束
            nums[j] = recodeList[i]
            j += 1
        for i in range(startIdx): # 0到開始的index
            nums[j] = recodeList[i]
            j += 1

        

if __name__ == "__main__":
    sol = Solution()
    #nums = [1,2,3,4,5,6,7]
    #k = 3
    nums = [-1,-100,3,99]
    k = 2
    sol.rotate(nums, k)
    print(nums)
