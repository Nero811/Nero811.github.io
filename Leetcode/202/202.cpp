/* ************************************************************************
> File Name:     202.cpp
> Author:        Jack Yang
> Created Time:  2023年05月16日 (週二) 21時59分50秒
> Description:   Happy Number 
 ************************************************************************/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int GetNum(int n){
        int sum=0;
        while(n>0){
            sum+=((n%10) * (n%10));
            n/=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        vector<int>vec(100000,0);
        while(1){
           n=GetNum(n);
           if(n==1)return true;
           else if(vec[n]>0)return false;
           vec[n]++;           
        }
        return false;
    }
};
int main(){
    int n=19;
    Solution sol;
    bool result=sol.isHappy(n);
    if(result){
        cout << "true";
    }
    else{
        cout << "false";
    }
    return 0;
}
