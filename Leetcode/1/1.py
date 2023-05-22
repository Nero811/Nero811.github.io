from typing import List
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        lt=[]
        lt2=[]
        result=[]
        for i in nums:
            lt.append(i)
        for i in nums:
            lt.remove(i)
            if target-i in lt:
                lt2.append(i)
                lt2.append(target-i)
                break
            else:
                lt.append(i)
        for i in range(len(nums)):
            if nums[i] in lt2:
                result.append(i)
        return result
sol=Solution()
#nums=[3,2,4]
#nums=[2,7,11,15]
#nums=[3,3]
nums=[2222222,2222222]
target=4444444
#target=9
for i in sol.twoSum(nums,target):
    print(i," ")
