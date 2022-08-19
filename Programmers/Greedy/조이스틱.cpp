#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    for (char& ch : name)
    {
        answer += min(ch-'A', 'Z'-ch+1);
    }
    // 원점에서 출발하여 i 번째와 다음 next_i 까지 갈수 있는 방법은 3가지
    // i) 원점에서 마지막 char까지 이동 : 최저 보장 횟수 (적어도 이보다 많이 이동하지는 않는다)
    // 정방향 0 ~ i Count : A
    // 역방향 0 ~ next_i Count : B  
    // ii) 원점에서 i 까지 정방향 i 에서 원점으로 역방향 갔따가 다시 역방향으로 next_i까지 (사이에 i와 next_i 사이의 A는 이동할 필요가 없음으로 count 제외)
    //      A + A + B
    // iii) 원점에서 역방향으로 next_i까지 갔다가 다시 원점으로 정방향갔다가 정방향으로 i까지 (사이에 i와 next_i 사이의 A는 이동할 필요가 없음으로 count 제외)
    //      B + B + A
    // 이러한 과정을 반복하여 최소 이동 횟수를 구한다
    int len = name.length();
    // i) 원점에서 마지막 char까지 이동하는게 최저 보장 횟수
    int left_right = len - 1;
    for (int i = 0; i < len; ++i) {
        int next_i = i + 1;
        while (next_i < len && name[next_i] == 'A')
            next_i++;
        // ii)와 iii)중 이동횟수가 짧은 분기점의 최소 이동 횟수를 찾는다.
        left_right = min(left_right, i + len - next_i + min(i, len - next_i));
    }
    answer += left_right;
    return answer;
}
