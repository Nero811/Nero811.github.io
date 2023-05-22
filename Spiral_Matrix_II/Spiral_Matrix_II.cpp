#include <bits/stdc++.h>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int length=n*n,j=0,count=1,len,offset=0,left=0;
        vector<vector<int>> v2(n, vector<int>(n, 0));
        while(count<=length){
	        for(int i=offset;i<n-offset;i++){
	        	v2[j][i]=count;
	//        	cout << "[j][i]: " << j << " " << i << "  ";
	//        	cout << "v2[j][i]" << v2[j][i] << endl;
	        	if(count==length){
	        		return v2;
				}	        	
	        	count++;
			}
			offset++;
			while(j!=n-offset){
				j++;
				v2[j][n-offset]=count;
	//			cout << "[j][i]: " << j << " " << n-offset << "  ";
	//			cout << "v2[j][n-1]" << v2[j][n-offset] << endl;
	        	if(count==length){
	        		return v2;
				}	 				
				count++;	
			}
			for(int i=n-1-offset;i>=left;i--){
	        	v2[j][i]=count;
	//        	cout << "[j][i]: " << j << " " << i << "  ";
	//        	cout << "v2[j][i]" << v2[j][i] << endl;
	        	if(count==length){
	        		return v2;
				}	 	        	
	        	count++;				
			}
			while(j>offset){
				j--;
				v2[j][left]=count;
	//			cout << "[j][i]: " << j << " " << left << "  ";				
	//			cout << "v2[j][left]" << v2[j][left] << endl;
	        	if(count==length){
	        		return v2;
				}	 				
				count++;
			}			
			left++;
		}
		return v2;
    }
};

int main(){
	int n;	
	Solution sol;
	vector<vector<int>> v2;
	cin >> n;
	v2=sol.generateMatrix(n);
	for(int i=0;i<v2.size();i++){
		for(int j=0;j<v2[i].size();j++){
			cout << v2[i][j] << endl;
		}
	}	
	return 0;
}
