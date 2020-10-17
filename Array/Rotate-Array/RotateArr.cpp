#include <iostream>
using namespace std;

void reverse(int arr[], int n, int st, int en)
{
    while (st < en)
    {
        int temp = arr[st];
        arr[st] = arr[en];
        arr[en] = temp;
        st++;
        en--;
    }
}
int main()
{
    int n, arr[10], k;
    cout << "Size: ";
    cin >> n;
    cout << "Enter array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout<<"Enter k: ";
    cin>>k;
    reverse(arr, n, 0, n-1);
    reverse(arr, n, 0, k-1);
    reverse(arr, n, k, n-1);
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
