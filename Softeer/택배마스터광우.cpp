#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N,M,K;
	cin>>N>>M>>K;
	vector<int>rail;
	for(int i  = 0 ; i < N ; i++)
	{
		int temprail;
		cin>>temprail;
		rail.push_back(temprail);
	}

	sort(rail.begin(),rail.end());
	int nMin = -1;
	do{
		int cur=0, work=0;
        for(int i=0;i<K;i++){
            int r = M;
            while(1){
                r-=rail[cur];
                if(r<0) break;
                work+=rail[cur++];
                cur%=N;
            }	
        }
		if (nMin == -1)
			nMin = work;
		else
			nMin = min(nMin,work);
	}while(next_permutation(rail.begin(), rail.end()));

	cout<<nMin;
	return 0;
}
