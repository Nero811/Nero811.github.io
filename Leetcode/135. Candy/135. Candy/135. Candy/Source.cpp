#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int>candies(ratings.size(),1);
        for (int i = 1; i < candies.size();i++) {
            if (ratings[i]- ratings[i-1]>0) {
                if (candies[i-1]>1) {
                    candies[i] = candies[i - 1] + 1;
                }
                else {
                    candies[i]++;
                }
            }
            else if (ratings[i] - ratings[i - 1] < 0 && candies[i - 1]==1) {
                candies[i-1]++;
            }
        }
     /*   for (int i : candies) {
            cout << "i : "<< i << endl;
        }*/
        int min = INT16_MAX;
        for (int i = candies.size()-1; i >= 0; i--) {
            if (i-1>=0 && candies[i]>1 && candies[i]== candies[i-1]&& ratings[i]!= ratings[i-1]) {
         //       cout << "i: " << i << endl;
                candies[i-1] = candies[i] + 1;
            }
            else if (i - 1 >= 0 && candies[i] > 1  && ratings[i] < ratings[i - 1]) {
                if (candies[i - 1]< candies[i]+1) {
                    candies[i - 1] = candies[i] + 1;
                }
            }
        }
        /*for (int i : candies) {
            cout << "i : " << i << endl;
        }*/
        int result = 0;
        for (int i: candies) {
            result += i;
        }
        return result;
    }
};

int main() {
    vector<int> ratings;
    int val = -1;
    while (val != -100) {
        cin >> val;
        if (val != -100) {
            ratings.push_back(val);
        }
    }
    Solution sol;
    int result;
    result = sol.candy(ratings);
    cout << "result: " << result << endl;
    return 0;
}