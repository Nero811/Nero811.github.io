#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>vec(27,0);
        if (s.size() != t.size())return false;
        for (int i = 0; i < s.size();i++) {
            vec[s[i] - 'a' + 1]++;
        }
        for (int i = 0; i < t.size();i++) {
            if (vec[t[i] - 'a' + 1]<1) {
                return false;
            }
            else {
                vec[t[i] - 'a' + 1]--;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    string s = "anagram";
    string t = "nagaram";
    if (sol.isAnagram(s,t)) {
        cout << "true";
    }
    else {
        cout << "false";
    }
    return 0;
}