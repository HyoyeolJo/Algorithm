#include <string>
#include <vector>
using namespace std;
void dfs (int n, int i, vector<vector<int>> computers, vector<bool> &check)
{
    if(check[i] != true)
    {
        check[i] = true;
        for(int j = 0; j < n ; j++)
        {
            if(j != i && computers[i][j] == 1)
            {
               dfs(n, j, computers, check);
            }
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> check(n, false);
    
    for(int i = 0 ; i < n ; i++)
    {
        if(check[i] != true)
        {
            answer++;
            dfs(n, i, computers, check);
        }
    }
    return answer;
}
