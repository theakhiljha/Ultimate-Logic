#include<iostream>
using namespace std;

int smallest(int arr[], int n, int k)
{
    //to find postion of smallest element in subarray from k to n
    int pos=k, small=arr[k], i;
    for(int j=k+1; j<n; j++)
    {
        if(small>arr[j])
        {
            small=arr[j];
            pos=j;
        }
    }
    return pos;
}
void selsort(int arr[], int n)
{
    int pos, temp;
    for(int k=0; k<n; k++)
    {
        pos=smallest(arr, n, k);
        temp=arr[k];
        arr[k]=arr[pos];
        arr[pos]=temp;
    }
    cout << "Sorted array.." << endl;
    for (int i = 0; i <n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[100], size;
    cout << "Enter size: " << endl;
    cin >> size;
    cout << "Enter array: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    selsort(arr, size);
}
