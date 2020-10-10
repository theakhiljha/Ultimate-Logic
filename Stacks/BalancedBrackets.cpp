#include <iostream>
#include <string>
#include <stack>
using namespace std;
bool helper(string s){
	stack<char> stk;
	int i=0;
	int length = s.length();
	while(i<length){
		if(s[i]==')' || s[i]=='}'|| s[i]==']' ){
			if(stk.empty()){
				return false;
			}
			char top = stk.top();
			int j=1;
			while(j<3){
				int bk = top+j;
				if(s[i]==char(bk)){
					top = bk;
					break;
				}
				j++;
			}
			if(top!=s[i]){
				return false;
			}
			else{
				stk.pop();

			}

		}
		if(s[i]=='(' || s[i]=='{' || s[i]=='['){
			stk.push(s[i]);
		}
		i++;
	}
	if(!stk.empty()){
		return false;
	}
	return true;
		

}
int main(){
	string s;
	
	getline(cin,s);
	if(helper(s)){
		cout<<"true";
	}
	else{
		cout<<"false";
	}
	return 0;
	


}
