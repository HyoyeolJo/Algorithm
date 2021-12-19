#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    //가장 적게 걸리는 시간
    long long low = 1;
    //가장 오래걸리는 시간
    long long high = 0;
    for(auto e : times)
    {
        if(high < e)
            high = e;
    }
    high = high * n;
    
    //이분탐색
    while(low <= high)
    {
        //중간시간으로 각 심사관이 처리할 수 있는 인원 확인
        long long mid = (low+high)/2;
        long long count = 0;
        for(auto ee : times)
        {
            count+= (mid/ee);
        }
        // count가 인원수보다 많거나 같을 경우
        if(count >= n)
        {
            if(answer == 0)
            {
                answer = mid;
            }
            else
            {
                answer = min(answer, mid);
            }
            high = mid -1;
        }
        //count가 인원수보다 작을 경우
        else
        {
            low = mid + 1;
        }
    }
    return answer;
}
