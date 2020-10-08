#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort(people.begin(),people.end(), [](vector<int> a,vector<int> b)->bool{
        if(a[0]>b[0]) return true; 
        else if(a[0]==b[0]) return a[1]<b[1];
        else return false;
    });
    vector<vector<int>> ans;
        
    for(auto person:people)
    {
        ans.insert(ans.begin()+person[1],person);
    }
    return ans;
}

int main()
{
	int n;
	cin>>n;
	vector<vector<int>> a;
	for(int i=0;i<n;i++)
	{
		int height,num;
		cin>>height>>num;
		vector<int> temp;
		temp.push_back(height);
		temp.push_back(num);
		a.push_back(temp);
	}
	vector<vector<int>> v=reconstructQueue(a);
	for(int i=0;i<n;i++)
	{
		cout<<a[i][0]<<" "<<a[i][1]<<endl;
	}
	return 0;
}
