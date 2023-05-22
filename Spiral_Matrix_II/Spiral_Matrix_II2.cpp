#include <bits/stdc++.h>
#include<vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0)); // �ϥ�vector�w?�@?�G???
        int startx = 0, starty = 0; // �w?�C�`?�@?�骺�_�l��m
        int loop = n / 2; // �C?��`?�L���A�Ҧpn?�_?3�A���\loop = 1 �u�O�`?�@��A�x?��?���Ȼݭn???�z
        int mid = n / 2; // �x?��?����m�A�Ҧp�Gn?3�A ��?����m�N�O(1�A1)�An?5�A��?��m?(2, 2)
        int count = 1; // ��??�x?���C�@?�Ů�?��
        int offset = 1; // �ݭn����C�@??�M?��?�סA�C���`?�k?�ɦ�?�@��
        int i,j;
        while (loop --) {
            i = startx;
            j = starty;

            // �U��?�l���|?for�N�O��??�F�@��
            // ��?��R�W��?����k(��?�k?)
            for (j = starty; j < n - offset; j++) {
                res[startx][j] = count++;
            }
            // ��?��R�k�C?�W��U(��?�k?)
            for (i = startx; i < n - offset; i++) {
                res[i][j] = count++;
            }
            // ��?��R�U��?�k�쥪(��?�k?)
            for (; j > starty; j--) {
                res[i][j] = count++;
            }
            // ��?��R���C?�U��W(��?�k?)
            for (; i > startx; i--) {
                res[i][j] = count++;
            }

            // �ĤG��?�l��?�ԡA�_�l��m�n�U�ۥ[1�A �Ҧp�G�Ĥ@��_�l��m�O(0, 0)�A�ĤG��_�l��m�O(1, 1)
            startx++;
            starty++;

            // offset ����C�@�騽�C�@??�M?��?��
            offset += 1;
        }

        // �p�Gn?�_?��?�A�ݭn???�x?�̤�?����m?��
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
