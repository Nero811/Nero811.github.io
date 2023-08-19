from typing import List
import queue

class Solution:
    def sortArrayByParityII(self, nums: List[int]) -> List[int]:
        """using two points """
        evenIdx = 0
        oddIdx = 1
        result = [0] * len(nums)
        for value in nums:
            if value % 2 == 0:
                result[evenIdx] = value
                evenIdx += 2
            else:
                result[oddIdx] = value
                oddIdx += 2
        
        return result
            
        

if __name__ == "__main__":
    sol = Solution()
    nums = [4,2,5,7]
    print(sol.sortArrayByParityII(nums))
