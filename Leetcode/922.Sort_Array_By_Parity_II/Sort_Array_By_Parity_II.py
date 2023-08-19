from typing import List
import queue

class Solution:
    def sortArrayByParityII(self, nums: List[int]) -> List[int]:
        """using queue"""
        oddQue = queue.Queue()
        evenQue = queue.Queue()
        for value in nums:
            if value % 2 == 0:
                evenQue.put(value)
            else:
                oddQue.put(value)
        
        for i in range(len(nums)):
            if i % 2 == 0:
                nums[i] = evenQue.get()
            else:
                nums[i] = oddQue.get()
        
        return nums

if __name__ == "__main__":
    sol = Solution()
    nums = [4,2,5,7]
    print(sol.sortArrayByParityII(nums))
