class Solution:
    def GetNum(self, n: int)->int:
        sum=0
        while n>0:
            sum+=((n%10)*(n%10))
            n//=10
        return sum
    def isHappy(self, n: int) -> bool:
        lt=[0]*10000
        while True:
            n=self.GetNum(n)
            if n==1:
                return True
            elif lt[n] > 0:
                return False
            lt[n]+=1
        return False

sol=Solution()
n=19
print("True")if sol.isHappy(n)==True else print("flase")
