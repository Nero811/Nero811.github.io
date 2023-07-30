from typing import List

class Solution:
    def fourSumCount(self, nums1: List[int], nums2: List[int], nums3: List[int], nums4: List[int]) -> int:
        mp = {}
        result = 0
        for i in nums1:
            for j in nums2:
                if (i + j) not in mp:
                    mp[i + j] = 1
                else:
                    mp[i + j] += 1
        
        for i in nums3:
            for j in nums4:
                if (0 - (i + j)) in mp:
                    result += mp[0 - (i + j)]
        
        return result
    

sol = Solution()
nums1 = [1,2]
nums2 = [-2,-1]
nums3 = [-1,2]
nums4 = [0,2]
print(sol.fourSumCount(nums1, nums2, nums3, nums4))