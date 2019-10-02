#include <iostream>
using namespace std;

int main()
{
	int no=30;
	int no1=25;
	int *pointer, *p;
	
	p=&no1;
	pointer=&no;
	
	cout<<pointer<<endl;
	cout<<*pointer<<endl;
	
	cout<<p<<endl;
	cout<<*p;
	
	return 0;
	
}
