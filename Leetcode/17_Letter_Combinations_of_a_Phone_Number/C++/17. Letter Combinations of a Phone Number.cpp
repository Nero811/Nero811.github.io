#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Solution {
public:
	void backtracking(vector<string> &result,vector<char> path,vector<vector<char>> &new_digits,int depth,int startidx){
		if(path.size()==depth){
			string new_path="";
			for(auto a:path){
				new_path+=a;
			}
		//	cout << new_path << endl;
			result.push_back(new_path);
			return;
		}
		for(int i=startidx;i<new_digits.size();i++){
			for(int j=0;j<new_digits[i].size();j++){
				cout << new_digits[i][j] << endl;
				path.push_back(new_digits[i][j]);
				backtracking(result,path,new_digits,depth,startidx+1);
				path.pop_back();
			}	
			break;
		}
	}
    vector<string> letterCombinations(string digits) {
        int depth=digits.length();
        int startidx=0;
        vector<string> result;
     	if(depth==0){
    		return result;
		}       
        vector<char> path;
        vector<vector<char>>new_digits;
        for(int i=0;i<depth;i++){
        	if(digits[i]=='2'){
        		new_digits.push_back({'a','b','c'});
			}
			else if(digits[i]=='3'){
				new_digits.push_back({'d','e','f'});
			}
			else if(digits[i]=='4'){
				new_digits.push_back({'g','h','i'});				
			}
			else if(digits[i]=='5'){
				new_digits.push_back({'j','k','l'});
			}		
			else if(digits[i]=='6'){
				new_digits.push_back({'m','n','o'});
			}											
			else if(digits[i]=='7'){
				new_digits.push_back({'p','q','r','s'});
			}					
			else if(digits[i]=='8'){
				new_digits.push_back({'t','u','v'});
			}	
			else if(digits[i]=='9'){
				new_digits.push_back({'w','x','y','z'});
			}									
		}
        backtracking(result,path,new_digits,depth,startidx);
        return result;
    }
};
int main(){
	vector<string> result;
	Solution sol;
	string digits;
	cin >> digits;

	result=sol.letterCombinations(digits);
	for(int i=0;i<result.size();i++){
		cout << result[i]<< " ";
	}
	return 0;
} 
