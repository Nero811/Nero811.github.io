from typing import List

class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        nums2 = sorted(nums, reverse=True)
        result = []
        dic = {}
        for i in range(len(nums2)):
            dic[nums2[i]] = (len(nums2) - 1 - i)
        
        for value in nums:
            result.append(dic[value])

        return result

if __name__ == "__main__":
    sol = Solution()
    #nums = [8,1,2,2,3]
    #nums = [6,5,4,8]
    nums = [7,7,7,7]
    print(sol.smallerNumbersThanCurrent(nums))