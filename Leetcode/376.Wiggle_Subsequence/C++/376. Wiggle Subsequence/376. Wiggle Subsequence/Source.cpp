#include<bits/stdc++.h>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() == 1)return 1;
        int pre = 0;
        int cur = 0;
        int result = 0;
        for (int i = 0; i < nums.size()-1;i++) {
            cur = nums[i + 1] - nums[i];
            if ((pre>=0 && cur <0) || (pre<=0 && cur >0)) {
                result++;
                pre = cur;
            }
        }
        return result+1;
    }
};
int main() {
    vector<int> nums;
    int val = 0;
    while (val != -1) {
        cin >> val;
        if (val != -1) {
            nums.push_back(val);
        }
    }
    Solution sol;
    int result = 0;
    result = sol.wiggleMaxLength(nums);
    cout << "result: " << result << endl;
    return 0;
}