#include<iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N,K;
	cin>>N>>K;
	vector<float>subsum; // 부분합
	float sum = 0.0F;
	subsum.push_back(sum);
	for(int i = 0 ; i < N ; i++)
	{
		int tempscore;
		cin>>tempscore;
		sum+=static_cast<float>(tempscore);
		subsum.push_back(sum); // 1 ... N 부분합
	}
	for(int i = 0 ; i < K ; i++)
	{
		int start,end;
		cin>>start>>end;
		float sum = subsum[end] - subsum[start-1];
		int cnt = end-start+1;
		float fCnt = static_cast<float>(cnt);
		float avg = sum/fCnt;
		printf("%.2f\n", avg);
	}
	return 0;
}
