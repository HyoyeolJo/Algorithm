#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> N;
	for(int i = 0 ; i < 8 ; i++)
	{
		int temp;
		cin>>temp;
		N.push_back(temp);
	}
	vector<int>check = N;
	sort(check.begin(),check.end(),::less<>());
	bool bcheck = true;
	for(int i = 0 ; i < 8 ; i++)
	{
		if(N[i] != check[i])
		{
			bcheck = false;
			break;
		}
	}
	if(bcheck == true)
	{
		cout<<"ascending";
		return 0;
	}
	sort(check.begin(),check.end(),::greater<>());
	bcheck = true;
	for(int i = 0 ; i < 8 ; i++)
	{
		if(N[i] != check[i])
		{
			bcheck = false;
			break;
		}
	}
	if(bcheck == true)
	{
		cout<<"descending";
		return 0;
	}
	cout<<"mixed";
	return 0;
}
