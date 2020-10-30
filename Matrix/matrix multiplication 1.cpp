#include<iostream>
using namespace std;
main()
{  int i,j;
int a[3][3],b[3][3],c[3][3];
for(int i=0;i<3;i++)
{
  for(int j=0;j<=2;j++)
  {
  	cin>>a[i][j];
  }
  
}   cout<<"your knew array is"<<endl;
	for(int i=0;i<3;i++)
{
  for(int j=0;j<=2;j++)
  {
  	cout<<a[i][j]<<" ";
  }
  cout<<"\n";
}	



for(int i=0;i<3;i++)
{
  for(int j=0;j<=2;j++)
  {
  	cin>>b[i][j];
  }
  
}   cout<<"your knew array is"<<endl;
	for(int i=0;i<3;i++)
{
  for(int j=0;j<=2;j++)
  {
  	cout<<b[i][j]<<" ";
  }
  cout<<"\n";
}   
  for(int i=0;i<=2;i++)
  {
  	for(j=0;j<=2;j++)
  	{   c[i][j]=0;
  		for(int k=0;k<=2;k++)
  		{
  			c[i][j]=c[i][j]+a[i][k]*b[k][j];
  		}
  		
  	}
  	
  	
  }
  cout<<"mutiplication array is"<<endl;
  
for(i=0;i<=2;i++)
{
	for(j=0;j<=2;j++)
	{
		cout<<c[i][j]<<" ";
		
	}
	cout<<"\n";
}


}


