#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n=0;
	cout<<"enter the number";
	cin>>n;
		while(n!=1)
	{
		if(n%2==0)
		{
			
			cout<<n<<"-> ";
			n=n/2;

		}
		else 
		{
		cout<<n<<"-> ";
		n=3*n+1;
		}

	}
	cout<<n;
	return 0;
}
