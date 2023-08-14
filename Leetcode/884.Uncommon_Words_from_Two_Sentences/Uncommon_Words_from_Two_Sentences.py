from typing import List

class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        lt1 = s1.split(' ')
        lt2 = s2.split(' ')
        lt3 = lt1 + lt2
        dic = {}
        for item in lt3:
            if dic.get(item):
               dic[item] = dic.get(item) + 1
            else:
                dic[item] = 1
        result = []
        for key, value in dic.items():
            if value == 1:
                result.append(key)

        return result
    

sol = Solution()
#s1 = "this apple is sweet"
#s2 = "this apple is sour"

#s1 = "apple apple"
#s2 = "banana"

s1 = "s z z z s"
s2 = "s z ejt"
print(sol.uncommonFromSentences(s1, s2))

