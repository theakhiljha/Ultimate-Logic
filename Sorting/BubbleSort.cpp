#include <iostream>
using namespace std;

void swap(int *x, int *y){  //swapping
    
    int temp=*x;
    *x=*y;
    *y=temp;
}

int main()
{
  int arr[]={1,4,9,7,3};
  
  for(int i=0;i<4;i++){      //Bubble sort logic
      for(int j=0;j<5-i-1;j++){
          if(arr[j]>arr[j+1]){
              swap(&arr[j],&arr[j+1]);
          }
      }
  }
  for(int k=0;k<5;k++){   //display
      cout<<arr[k]<<" ";
  }

    return 0;
}