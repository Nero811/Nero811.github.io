#include <bits/stdc++.h>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        // 找出a + b + c = 0
        // a = nums[i], b = nums[j], c = -(a + b)
        for (int i = 0; i < nums.size(); i++) {
            // 排序之后如果第一?元素已?大于零，那么不可能?成三元?
            if (nums[i] > 0) {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) { //三元?元素a去重
                continue;
            }
            unordered_set<int> set;
            for (int j = i + 1; j < nums.size(); j++) {
                if (j > i + 2
                        && nums[j] == nums[j-1]
                        && nums[j-1] == nums[j-2]) { // 三元?元素b去重
                    continue;
                }
                int c = 0 - (nums[i] + nums[j]);
                if (set.find(c) != set.end()) {
                    result.push_back({nums[i], nums[j], c});
                    set.erase(c);// 三元?元素c去重
                } else {
                    set.insert(nums[j]);
                }
            }
        }
        return result;
    }
};

int main(){
	int op1;
	vector<int> nums;
	Solution sol;
	while(op1!=-5){
		cin >> op1;
		if(op1!=-5){
			nums.push_back(op1);
		}
	}		
	sol.threeSum(nums);
	return 0;
}

