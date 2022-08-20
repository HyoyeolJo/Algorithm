#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int>setN;
	vector<int>setM;
	int N,M;
	cin>>N>>M;
	for(int i = 0 ; i < N ; i++)
	{
		int areaDist,speed;
		cin>>areaDist>>speed;
		while(areaDist--)
			setN.push_back(speed);
	}
	for(int i = 0 ; i < M ; i++)
	{
		int areaDist,speed;
		cin>>areaDist>>speed;
		vector<int> temp;
		while(areaDist--)
			setM.push_back(speed);
	}
	int nMax = 0;
	for(int i = 0 ; i < 100; i++)
	{
		nMax= max(nMax, setM[i]-setN[i]);
	}
	cout<<nMax;
	return 0;
}
