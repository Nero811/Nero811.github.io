#include<bits/stdc++.h>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    void backtracking(int startidx, vector<int>& nums, vector<int>&path, vector<int>&wiggle, int &result) {
        if (path.size() > result) {
            result = path.size();
        }
        if (startidx>nums.size()-1) {
         /*   for (int& i : path) {
                cout << i << " ";
            }
            cout << endl;*/
            wiggle.clear();
            return;
        }
        for (int i = startidx; i < nums.size();i++) {
            if (i>0 && nums[i]==nums[i-1]) {
        //        cout << "888" << endl;
                continue;
            }
            if (!path.empty() && i>0) {
                if (!wiggle.empty() && nums[i]-path.back()>0 && wiggle.back()==0) {
         //           cout << "666" << endl;
                    wiggle.push_back(1);
                }
                else if (!wiggle.empty() && nums[i]- path.back() < 0 && wiggle.back()== 1) {
         //           cout << "777" << endl;
                    wiggle.push_back(0);
                }
                else if (nums[i] - path.back() ==0) {
        //            cout << "111" << endl;
                    continue;
                }
                else if(!wiggle.empty() && nums[i] - path.back() < 0 && wiggle.back() == 0){
         //           cout << "222" << endl;
                    continue;
                }
                else if (!wiggle.empty() && nums[i] - path.back() > 0 && wiggle.back() == 1) {
         //           cout << "333" << endl;
                    continue;
                }
                if (wiggle.empty()) {
                    if (nums[i] - path.back() > 0) {
         //               cout << nums[i] << endl;
                        wiggle.push_back(1);
                    }
                    else if (nums[i] - path.back() < 0) {
                        wiggle.push_back(0);
                    }
                }
            }
            path.push_back(nums[i]);
            backtracking(i+1, nums, path, wiggle, result);
            path.pop_back();
        }
    }
    int wiggleMaxLength(vector<int>& nums) {
        vector<int>path;
        vector<int>wiggle;
        int result=0;
        int startidx = 0;
        if (nums.size()==1)return 1;
        backtracking(startidx, nums, path, wiggle, result);
        return result;
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
