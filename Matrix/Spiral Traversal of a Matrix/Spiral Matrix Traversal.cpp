#include<iostream>
using namespace std;
void spiralForm(int a[][10],int i1,int i2,int j1,int j2)
{
    if(i1==i2)
    {
        while(j1<=j2)
        {
            cout<<a[i1][j1]<<" "; 
            j1++;
        }
        return;
    }
    else if(j1==j2)
    {
        while(i1<=i2)
        {
            cout<<a[i1][j1]<<" ";
            i1++;
        }
        return;
    }
    else
    {
        int i,j;
        i=i1,j=j1;
        while(j<=j2)
        {
            cout<<a[i][j]<<" ";
            j++;
        }
        i++,j--;
        while(i<=i2)
        {
            cout<<a[i][j]<<" ";
            i++;
        }
        i--,j--;
        while(j>=j1)
        {
            cout<<a[i][j]<<" ";
            j--;
        }
        i--,j++;
        while(i>=i1+1)
        {
            cout<<a[i][j]<<" ";
            i--;
        }
        if(i1+1>i2-1||j1+1>j2-1)
        {
            return;
        }
        else
        {
            spiralForm(a,i1+1,i2-1,j1+1,j2-1);
        }
    }
}
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int m,n;
	    cin>>m>>n;
	    int a[m][10];
	    for(int i=0;i<m;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            cin>>a[i][j];
	        }
	    }
	    spiralForm(a,0,m-1,0,n-1);
	    cout<<endl;
	}
	return 0;
}