#include <bits/stdc++.h>
#include<vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0)); // 使用vector定?一?二???
        int startx = 0, starty = 0; // 定?每循?一?圈的起始位置
        int loop = n / 2; // 每?圈循?几次，例如n?奇?3，那么loop = 1 只是循?一圈，矩?中?的值需要???理
        int mid = n / 2; // 矩?中?的位置，例如：n?3， 中?的位置就是(1，1)，n?5，中?位置?(2, 2)
        int count = 1; // 用??矩?中每一?空格?值
        int offset = 1; // 需要控制每一??遍?的?度，每次循?右?界收?一位
        int i,j;
        while (loop --) {
            i = startx;
            j = starty;

            // 下面?始的四?for就是模??了一圈
            // 模?填充上行?左到右(左?右?)
            for (j = starty; j < n - offset; j++) {
                res[startx][j] = count++;
            }
            // 模?填充右列?上到下(左?右?)
            for (i = startx; i < n - offset; i++) {
                res[i][j] = count++;
            }
            // 模?填充下行?右到左(左?右?)
            for (; j > starty; j--) {
                res[i][j] = count++;
            }
            // 模?填充左列?下到上(左?右?)
            for (; i > startx; i--) {
                res[i][j] = count++;
            }

            // 第二圈?始的?候，起始位置要各自加1， 例如：第一圈起始位置是(0, 0)，第二圈起始位置是(1, 1)
            startx++;
            starty++;

            // offset 控制每一圈里每一??遍?的?度
            offset += 1;
        }

        // 如果n?奇?的?，需要???矩?最中?的位置?值
        if (n % 2) {
            res[mid][mid] = count;
        }
        return res;
    }
};


int main(){
	int n;	
	Solution sol;
	cin >> n;
	sol.generateMatrix(n);
}
