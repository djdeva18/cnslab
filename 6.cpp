#include <iostream>
#include <cmath>
using namespace std;

long long int power(long int g, long long int a, long long int p)
{
	if(a==1)
		return g;
	return (long long int)pow(g,a)%p;
}

int main()
{
	long long int p,g,a,b,x,y,ka,kb;
	cout<<"\t---DIFFIE HELLMAN KEY EXCHANGE---"<<endl;
	
	cout<<"Enter the public key values:"<<endl;
	cout<<"P: ";
	cin>>p;
	cout<<"G: ";
	cin>>g;
	
	cout<<"Enter the private keys:"<<endl;
	cout<<"For Alice-a: ";
	cin>>a;
	cout<<"For Bob-b: ";
	cin>>b;
	
	x = power(g,a,p);
	y = power(g,b,p);
	
	cout<<"Alice received: "<<y<<endl;
	cout<<"Bob received: "<<x<<endl;
	
	ka = power(y,a,p);
	kb = power(x,b,p);
	
	cout<<"Secret key for Alice: "<<ka<<endl;
	cout<<"Secret key for Bob: "<<kb<<endl;
	
	return 0;	
}
