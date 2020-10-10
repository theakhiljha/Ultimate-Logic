#include <iostream>
#include <string>
#include <stack>
#include <algorithm> 
#include <vector>
using namespace std;

vector<int> helper(stack<pair<int,int>> stk,int arr[],std::vector<int> v,int n){
	for( int i=0;i<n;i++){
		if(stk.empty()){
			v.push_back(-1);

		}
		else if(!stk.empty() && stk.top().first < arr[i]){
			v.push_back(stk.top().second);
		}
		else if(!stk.empty()&& stk.top().first>=arr[i]){
			while(!stk.empty()&& stk.top().first>=arr[i]){
				stk.pop();
			}
			if(stk.empty()){
				v.push_back(-1);
			}
			else{
				v.push_back(stk.top().second);
			}
		}
		stk.push({arr[i],i});

	}
	return v;
}
vector<int> helper2(stack<pair<int,int>> stk,int arr[],std::vector<int> v,int n){
	for( int i=n-1;i>=0;i--){
		if(stk.empty()){
			v[i] = (n)-1-v[i];
		}
		else if(!stk.empty() && stk.top().first<arr[i]){
			v[i]=(stk.top().second)-1-v[i];
		}
		else if(!stk.empty()&& stk.top().first>=arr[i]){
			while(!stk.empty()&& stk.top().first>=arr[i]){
				stk.pop();
			}
			if(stk.empty()){
				v[i]=(n)-1-v[i];
			}
			else{
				v[i]=(stk.top().second)-1-v[i];
			}
		}
		stk.push({arr[i],i});

	}
	return v;
}

int main(){
	
	int n;
	cin>>n;
	int arr[n];
	vector<int> right;
	
	stack<pair<int,int> > stk;
    
	for(int i=0;i<n;++i){
		cin>>arr[i];
	}
	right = helper(stk,arr,right,n);
    while(!stk.empty()){
        stk.pop();
    }
    
   
    right = helper2(stk,arr,right,n);
    int max=0;
     for(int i=0;i<n;i++){
       int a = right[i]*arr[i];
        if(a>max){
            max = a;
        }
    }
  cout<<max;
    return 0;
    

	

	


}
