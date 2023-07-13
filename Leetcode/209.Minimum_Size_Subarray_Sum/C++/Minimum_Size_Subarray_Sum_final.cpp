#include <bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int result = INT32_MAX;
        int sum = 0; // ��?���f?�Ȥ��M
        int i = 0; // ��?���f�_�l��m
        int subLength = 0; // ��?���f��?��
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            // �`�N?���ϥ�while�A�C����s i�]�_�l��m�^�A�}��?��?�l�ǦC�O�_�ŦX?��
            while (sum >= s) {
                subLength = (j - i + 1); // ���l�ǦC��?��
                cout << "subLength: " << subLength << endl;
                result = result < subLength ? result : subLength;
                cout << "result: " << result << endl;
                cout << "sum: " << sum << endl;
                sum -= nums[i++]; // ?���^?�X��?���f�����褧?�A��??��i�]�l�ǦC���_�l��m�^
                cout << "sum -= nums[i++] " << sum << endl;
            }
        }
        // �p�Gresult?���Q?�Ȫ�?�A�N��^0�A?��?���ŦX?�󪺤l�ǦC
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
