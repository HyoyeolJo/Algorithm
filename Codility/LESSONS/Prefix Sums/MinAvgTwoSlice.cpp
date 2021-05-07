/*
0 - 0 4 = 4
0 - 1 4+2 = 6
0 - 2 4+2+2 = 8
0 - 3 4+2+2+5 = 13
0 - 4 4+2+2+5+1 = 14
0 - 5 4+2+2+5+1+5 = 19
0 - 6 4+2+2+5+1+5+8 = 27
if 1 - 2, prfix[0 - 2]- prefix[0 - 1] + A[start]
if 1 - 3, 0 - 3까지 합에서 0 - 1 까지 합을 뺀다음 시작 원소를 더한다
추가되는 원소가 이전 평균값보다 작을 경우에 포함하면 전체 평균이 작아진다
*/
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> pre_sum(A.size());
    int pre_s = 0;
    for(unsigned int i = 0U; i < A.size() ; i++)
    {
        pre_s += A[i];
        pre_sum[i] = pre_s;
    }
    int end = 1;
    int start = 0;
    int min_start = start;
    float minAvg = static_cast<float>(pre_sum[end] - pre_sum[start] + A[start]) / (end-start+1);
    for(unsigned i = 1U; i<A.size(); i++)
    {
        float minSubAvg = static_cast<float>(pre_sum[i] - pre_sum[start] + A[start]) / (i-start+1);
        if (minSubAvg < minAvg)
        {
            minAvg = minSubAvg;
            min_start = start;
        }

        if (A[i] < minAvg)
        {
            start = i;
        }
    }
    return min_start;
}
