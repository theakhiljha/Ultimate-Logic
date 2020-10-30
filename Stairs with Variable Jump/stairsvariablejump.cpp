#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++ ){
        cin>>arr[i];
    }
    int t[n+1]={0};
    t[n]=1;
    
    for(int i=n-1;i>=0;i--){
        for(int j=1;j<=arr[i] && i+j<=n;j++){
        t[i]+= t[i+j];}
        
    }
    cout<<t[0];
    return 0;
}
