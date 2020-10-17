#include<iostream>
using namespace std;

void insertsort(int size, int arr[])
{
    int temp;
    for(int i=1; i<size; i++)
    {
        temp=arr[i];
        int hole=i;
        while(hole>0 && arr[hole-1]>temp)
        {
            //shifting of elements to the right
            arr[hole]=arr[hole-1];
            hole--;
        }
        arr[hole]=temp;
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
    cout << "Enter size: " << endl;
    cin >> size;
    cout << "Enter array: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    insertsort(size, arr);
}