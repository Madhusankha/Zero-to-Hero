#include<iostream>
#include<math.h>
using namespace std;
int main() {
  cout<<"input your number for prime testing:  ";
  long long number_under_test;
  cin>>number_under_test;
  bool is_prime = true;
  long long devider = 2;
  long long maximum_limit = sqrt(number_under_test);
  while(devider <= maximum_limit){
     if(number_under_test%devider == 0){
       is_prime = false;
       break;
     }
     devider++;
  }
  if(is_prime){
    cout<<"is a prime number"<<endl;
  }else{
   cout<<"is not a prime number"<<endl;
  }
}
