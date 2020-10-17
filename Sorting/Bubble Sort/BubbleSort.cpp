#include<iostream>
using namespace std;

void bubblesort(int size, int arr[])
{
    int flag=0;
    for(int i=0; i<size; i++)
    {
        for(int j=i+1; j<size; j++)
        {
            if(arr[i]>arr[j])
            {
                flag=1;     //optimization
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
        if(flag==0)
            return; 
    }
    cout<<"Sorted array.."<<endl;
    for(int i=0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int arr[100], size;
    cout<<"Enter size: "<<endl;
    cin>>size;
    cout<<"Enter array: "<<endl;
    for(int i=0; i<size; i++)
    {
        cin>>arr[i];
    }
    bubblesort(size, arr);
}
