#include<iostream>


using namespace std;
unsigned long long recursive (int n, unsigned long long a1)
{
	if(n == 0)
	{
		return a1;
	}
	unsigned long long an = 2*a1 -1;
	recursive(n-1, an);
}

int main(int argc, char** argv)
{
	int n;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	unsigned long long a1 = 2;
	unsigned long long an = 0;
	if(n == 0)
		cout<<a1*a1;
	else
	{
		an = recursive(n,a1);
		cout<<an*an;
	}
	return 0;
}
