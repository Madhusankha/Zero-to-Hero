#include<iostream>
using namespace std;

int linearsearch(int *a,int n,int x){
    int i=0;
    while(i!=n&&a[i]!=x){
        i++;
    }
    if(i==n){
        return -1;
    }
    else{
        return i;
    }
}

int main(){
    int n,x;
    cout<<"Enter size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter element to find: ";
    cin>>x;
    int res = linearsearch(arr,n,x);
    if(res==-1){
        cout<<"Element not found";

    }
    else{
        cout<<"Element found at index "<<res;
    }


}
