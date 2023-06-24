#include<bits/stdc++.h>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        if (prices.size()==1) {
            return 0;
        }
        for (int i = 1; i < prices.size();i++) {
            if (prices[i]- prices[i-1]>0) {
                result += (prices[i] - prices[i - 1]);
            }
        }
        return result;
    }
};
int main() {
    vector<int> prices;
    int val = 0;
    while (val != -100) {
        cin >> val;
        if (val != -100) {
            prices.push_back(val);
        }
    }
    Solution sol;
    int result = 0;
    result = sol.maxProfit(prices);
    cout << "result: " << result << endl;
    return 0;
}