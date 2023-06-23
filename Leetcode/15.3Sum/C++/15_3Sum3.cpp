#include <bits/stdc++.h>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        // ��Xa + b + c = 0
        // a = nums[i], b = nums[j], c = -(a + b)
        for (int i = 0; i < nums.size(); i++) {
            // �ƧǤ��Z�p�G�Ĥ@?�����w?�j�_�s�A���\���i��?���T��?
            if (nums[i] > 0) {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) { //�T��?����a�h��
                continue;
            }
            unordered_set<int> set;
            for (int j = i + 1; j < nums.size(); j++) {
                if (j > i + 2
                        && nums[j] == nums[j-1]
                        && nums[j-1] == nums[j-2]) { // �T��?����b�h��
                    continue;
                }
                int c = 0 - (nums[i] + nums[j]);
                if (set.find(c) != set.end()) {
                    result.push_back({nums[i], nums[j], c});
                    set.erase(c);// �T��?����c�h��
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

