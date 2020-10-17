#include<iostream>
using namespace std;
#define size 100
void merge(int arr[], int beg, int mid, int end)
{   
    //function to combine 2 arrays 
    int i=beg, j=mid+1, index=beg, temp[size], k;
    while((i<=mid) && (j<=end))
    {
        if(arr[i]<arr[j])
        {
            temp[index]=arr[i];
            i++;
        }
        else
        {
            temp[index]=arr[j];
            j++;
        }
        index++;
    }
    if(i>mid)
    {
        while(j<=end)
        {
            temp[index]=arr[j];
            index++;
            j++;
        }
    }
    else
    {
        while(i<=mid)
        {
            temp[index]=arr[i];
            index++;
            i++;
        }
    }
    for(int k=0; k<index; k++)
    {
        arr[k]=temp[k];
    }
}
void mergesort(int arr[], int beg, int end)
{
    int mid;
    if(beg<end)
    {
        mid=(beg+end)/2;
        mergesort(arr, beg, mid);
        mergesort(arr, mid+1, end);
        merge(arr, beg, mid, end);
    }
}
int main()
{
    int arr[100], n;
    cout << "Enter size: " << endl;
    cin >> n;
    cout << "Enter array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    mergesort(arr, 0, n-1);
    cout<<"Sorted array..."<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
