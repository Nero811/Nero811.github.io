#include <bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int result = INT32_MAX;
        int sum = 0; // 滑?窗口?值之和
        int i = 0; // 滑?窗口起始位置
        int subLength = 0; // 滑?窗口的?度
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            // 注意?里使用while，每次更新 i（起始位置），并不?比?子序列是否符合?件
            while (sum >= s) {
                subLength = (j - i + 1); // 取子序列的?度
                cout << "subLength: " << subLength << endl;
                result = result < subLength ? result : subLength;
                cout << "result: " << result << endl;
                cout << "sum: " << sum << endl;
                sum -= nums[i++]; // ?里体?出滑?窗口的精髓之?，不??更i（子序列的起始位置）
                cout << "sum -= nums[i++] " << sum << endl;
            }
        }
        // 如果result?有被?值的?，就返回0，?明?有符合?件的子序列
        return result == INT32_MAX ? 0 : result;
    }
};

int main(){
	vector<int> nums;	
	Solution sol;
	int n;
	while(n != -2){
		cin >> n;
		if(n != -2){
			nums.push_back(n);	
		}
	}
	cin >> n;
	sol.minSubArrayLen(n,nums);
}
