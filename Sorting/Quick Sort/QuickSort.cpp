#include<iostream>
using namespace std;

int Partition(int arr[], int start, int end)
{
    int pIndex=start, pivot=arr[end];
    for(int i=start; i<end; i++)
    {
        if(arr[i]<=pivot)
        {
            int temp=arr[i];
            arr[i]=arr[pIndex];
            arr[pIndex]=temp;
            pIndex+=1;
        }
    }
    int temp=arr[end];
    arr[end]=arr[pIndex];
    arr[pIndex]=temp;
    return pIndex;
}
void quicksort(int arr[], int start, int end)
{
    if(start<end)
    {
        int part=Partition(arr, start, end);
        quicksort(arr, start, part-1);
        quicksort(arr, part+1, end);
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
    quicksort(arr, 0, n - 1);
    cout << "Sorted array..." << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
