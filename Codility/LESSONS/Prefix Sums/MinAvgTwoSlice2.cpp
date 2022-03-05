// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> prefix;
    int presum = 0;
    for(auto e : A)
    {
        presum+=e;
        prefix.push_back(presum);
    }
    int start = 0;
    int end = 1;
    int slicesum = prefix[end] - prefix[start] + A[start];
    float avg = static_cast<float>(slicesum) / (end-start+1);
    float checkavg = avg;
    int resultstart = start;
    for(unsigned int i = 1U; i < A.size() ; i++)
    {
        slicesum = prefix[i] - prefix[start] + A[start];
        avg = static_cast<float>(slicesum) / (i-start+1);

        // 구간 내의 평균값이 작으면 result start 와 최소 평균값을 갱신한다
        if(checkavg > avg)
        {
            checkavg = avg;
            resultstart = start;
        }
        // 현재 평균보다 A[i]값이 작으면 평균이 작아지므로 start 위치를 바꿔준다
        if (A[i] < checkavg)
        {
            start = i;
        }
    }
    return resultstart;
}
