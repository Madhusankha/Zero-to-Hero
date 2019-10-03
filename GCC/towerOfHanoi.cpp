#include<iostream>
using namespace std;
void move(int n,string a,string b,string c){
    if(n==1){
        cout<<"Move 1 disk from "<<a<<" to "<<c<<endl;
    }
    else{
        move(n-1,a,c,b);
        move(1,a,b,c);
        move(n-1,b,a,c);
    }
}

int main(){

    int n;
    cout<<"Enter number of disks: ";
    cin>>n;
    move(n,"Source","Intermediate","Destination");
    return 0;
}
