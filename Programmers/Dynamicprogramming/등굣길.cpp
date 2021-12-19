#include <string>
#include <vector>
#include <iostream>
using namespace std;
//n -> x, m -> y
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>> map(101,vector<int>(101,0));
    for(int i = 0 ; i < puddles.size(); i++)
    {
        map[puddles[i][1]][puddles[i][0]] = -1;
    }
    //dp
    map[1][1] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j  = 1 ; j <= m; j++)
        {
            int a=0; 
            int b=0; 
            if(map[i][j]==-1) 
                continue; 
            if(map[i-1][j]!=-1) 
                a= map[i-1][j]; 
            if(map[i][j-1]!=-1) 
                b= map[i][j-1]; 
            map[i][j]+=(a+b)%1000000007;
        }
    }
    answer = map[n][m];
    return answer;
}
