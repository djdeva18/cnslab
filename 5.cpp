#include <iostream>
#include <cmath>
using namespace std;

int p,q,n,phi,e,d;

int gcd(int a, int b)
{
	if(a==0)
		return b;
	return gcd(b%a,a);
}

void generateKey()
{
	cout<<"Enter the value of 'p' and 'q': ";
	cin>>p>>q;
	
	n = p*q;
	phi = (p-1)*(q-1);
	
	e = 2;
	while(e<phi)
	{
		if(gcd(e,phi)==1)
			break;
		else
			e++;	
	}
	
	int k = 0;
	while(1)
	{
		int temp = (1+(k*phi))%e;
		if(temp==0)
		{
			d = (1+(k*phi))/e;
			break;	
		}
		else
			k++;
	}	
}

void encrypt()
{
	cout<<"Enter the message(integer): ";
	int msg;
	cin>>msg;
	
	double c = pow(msg,e);
	c = fmod(c,n);
	cout<<"The ciphered msg is: "<<c<<endl;
}

void decrypt()
{
	cout<<"Enter the ciphered msg(integer): ";
	int c;
	cin>>c;
	
	double p = pow(c,d);
	p = fmod(p,n);
	cout<<"The deciphered message is: "<<p<<endl;
}

int main()
{
	generateKey();
	
	/*
	cout<<"p:"<<p<<endl;
	cout<<"q:"<<q<<endl;
	cout<<"n:"<<n<<endl;
	cout<<"phi:"<<phi<<endl;
	cout<<"e:"<<e<<endl;
	cout<<"d:"<<d<<endl;
	*/
	
	while(1)
	{
		cout<<"\n\t---RSA ALGORITHM---\n";
		cout<<"Enter Choice:\n";
		int c;
		cout<<"1-Encrypt\n2-Decrypt\n3-Exit\n";
		cin>>c;
		
		switch(c)
		{
			case 1: encrypt();
					break;
			case 2: decrypt();
					break;
			case 3: return 0;
			default: cout<<"Enter correct choice\n";			
		}
	}
	return 0;
}
