#include <string>
#include <vector>
#include <queue>

using namespace std;

//기본적으로 소요되는 시간이 적은 순으로 정렬
struct compare{
    bool operator()(vector<int> a, vector<int> b){
        return a[1] > b[1]; // a 가 b보다 크면 true -> Swap 즉, 앞쪽의 값이 작아짐
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    // 소요시간 우선순위 큐
    priority_queue <vector<int>, vector<vector<int>>, compare>pq;
    // 작업중이 상태 확인
    vector<bool>check(jobs.size(), false);
    int sum = 0; // 이어서 진행하는 전체 소요시간의 누적합
    int used = 0; // 사용된 작업

    while (used < jobs.size()) {
        for (int i = 0; i < jobs.size(); i++) {
            if (!check[i] && jobs[i][0] <= sum) {
                // sum 영역 안에 있는 작업사항 우선 전부 수집 (우선순위 적용)
                pq.push(jobs[i]);
                check[i] = true; // 작업중
            }
        }
        // 작업할 대상이 없을 경우, 1초의 시간을 흘린다.
        if (pq.empty()) {
            sum++; continue;
        }
        vector<int> temp = pq.top();
        //요청으로부터 현재 작업 종료까지 소요시간
        answer += sum - temp[0] + temp[1];
        sum += temp[1];
        pq.pop();
        used++;
    }
    return answer / jobs.size();
}
