#include<iostream>
#include<vector>
#include<algorithm>
#include<string>


using namespace std;
int globalcnt;
void dfs(int N, int i,int j, vector<vector<int>>block, vector<vector<bool>>&check)
{
	if(i < 0 || j < 0) return;
    if(i >= N || j >= N) return;
    if(block[i][j] ==0) return;
    if(check[i][j] == true) return;
    else check[i][j] = true;
    int di[4]={1, -1, 0, 0};
	int dj[4]={0, 0, 1, -1};
	globalcnt++;
    for(int index=0; index<4; index++)
    {   
		int ni=i+di[index];
        int nj=j+dj[index];
        dfs(N, ni, nj, block, check);
    }
}
int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin>>N;
	vector<vector<int>>block(N, vector<int>(N,0));
	vector<vector<bool>>check(N, vector<bool>(N,false));
	vector<int>blockcountset;
	for(int i = 0 ; i < N ; i++)
	{
		string area;
		cin>>area;
		for(int j = 0 ; j < N ; j++)
		{
			block[i][j] = area[j]-48;
		}
	}
	for(int i = 0; i < N; i++)
	{
		for(int j = 0 ; j < N ; j++)
		{
			if(check[i][j] == false && block[i][j] > 0)
			{
				globalcnt = 0;
				dfs(N, i, j, block, check);
				blockcountset.push_back(globalcnt);
				
			}
		}
	}

	sort(blockcountset.begin(), blockcountset.end());
	cout<<blockcountset.size()<<endl;
	for(auto e : blockcountset)
	{
		cout<<e<<endl;
	}
	return 0;
}
