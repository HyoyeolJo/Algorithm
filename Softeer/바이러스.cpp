#include<iostream>


using namespace std;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int K,P,N;
	cin>>K>>P>>N;
	unsigned long long int ulK, ulP;
	ulK = K;
	ulP = P;
	while(N--)
	{
		ulK = (ulK*ulP)%1000000007;
	}
	cout<<ulK;
	return 0;
}
