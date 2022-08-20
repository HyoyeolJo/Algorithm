#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare (pair<int,int> A, pair<int,int> B)
{
	return A.second > B.second;
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int W,N;
	cin>>W>>N;
	vector<pair<int,int>>Metals;
	for(int i = 0 ; i < N ; i++)
	{
		int M, P;
		cin>>M>>P;
		Metals.push_back({M,P});
	}
	sort(Metals.begin(), Metals.end(), compare);
	int sum = 0;
	int curW = 0;
	for(auto e : Metals)
	{
		if(curW + e.first < W)
		{
			curW+=e.first;
			sum+=(e.first*e.second);
		}
		else
		{
			sum+=((W-curW)*e.second);
			break;
		}
	}
	cout<<sum;
	return 0;
}
