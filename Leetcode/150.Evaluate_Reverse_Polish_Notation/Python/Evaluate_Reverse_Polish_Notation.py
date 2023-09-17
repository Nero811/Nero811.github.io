from typing import List

class Solution:
    def __init__(self):
        self.sum = 0

    def calculate(self, numStack, operator):
        num1 = numStack.pop()
        num2 = numStack.pop()
        if operator == "+":
            self.sum = num2 + num1
        elif operator == "-":
            self.sum = num2 - num1
        elif operator == "*":
            self.sum = num2 * num1
        elif operator == "/":
            self.sum = int(num2 / num1)


    def evalRPN(self, tokens: List[str]) -> int:
        if len(tokens) == 1:
            return int(tokens.pop())
        numStack = []
        for item in tokens:
            if item == "+":
                self.calculate(numStack,"+")
                numStack.append(self.sum)
            elif item == "-":
                self.calculate(numStack,"-")
                numStack.append(self.sum)
            elif item == "*":
                self.calculate(numStack,"*")
                numStack.append(self.sum)
            elif item == "/":
                self.calculate(numStack,"/")
                numStack.append(self.sum)
            else:
                numStack.append(int(item))
        
        return self.sum

if __name__ == "__main__":
    #tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
    tokens = ["4","13","5","/","+"]
    #tokens = ["3","11","+","5","-"]
    sol = Solution()
    print(sol.evalRPN(tokens))
                    
            
                
        
