#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    vector<long long> temp(n+1, 0);
    temp[1] = 1; // 1층가지 갈 수 있는 경우의 수
    temp[2] = 2; // 2층까지 갈 수 있는 경우의 수
    //temp[3] = temp[2] + temp[1]; // 3층까지 갈수 있는 경우의 수
    //...
    //temp[n] 까지 갈수 있는 경우의 수 temp[n] = temp[n-2]+temp[n-1];
    for(int i = 3; i <= n ; i++)
    {
        temp[i] = (temp[i-2] + temp[i-1])%1234567;
    }
    return answer = temp[n];
}
