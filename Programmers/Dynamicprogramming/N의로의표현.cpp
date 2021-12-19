#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int solution(int N, int number) {
    int answer = 1;
    vector<unordered_set<int>> func(9);
    //func1
    // N이 1개일 때 Set 저장
    func[1].insert(N);
    int n = 0;
    for(answer = 1; answer < 9 ; answer++)
    {
        //setting N, NN, NNN...
        n = n*10+N;
        if(answer > 1)
        {
            //Set
            //N,NN,NNN 일때 Set 저장
            func[answer].insert(n);
            //Func(N-1)...Func(1) 까지 사칙연산과
            //Func(1)...(Func(N-1)까지 사칙연산을 Set으로 저장
            for( int i  = 1 ; i < answer; i++)
            {
                for(int j  = answer-i ; j > 0 ; j--)
                {
                    for(auto ea : func[i])
                    {
                        for(auto eb : func[j])
                        {
                            func[answer].insert(ea+eb);
                            // 음수로 계속 더해지는 건 의미가 없음
                            if ((ea-eb) > 0)
                            {
                                func[answer].insert(ea-eb);
                            }
                            func[answer].insert(ea*eb);
                            // 0으로 나누면 안됨
                            if(eb > 0)
                            {
                                func[answer].insert(ea/eb);
                            }
                        }
                    }
                }
            }            
        }
        //연산된 값이 number인 set을 찾으면 반복문 종료
        if(func[answer].find(number) != func[answer].end())
        {
            break;
        }
    }
    if(answer == 9)
    {
        answer = -1;
    }
    return answer;
}
