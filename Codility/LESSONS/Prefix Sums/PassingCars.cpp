// you can use includes, for example:
// #include <algorithm>

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> pre_sum(A.size());
    int pre_S = 0;
    for (unsigned int i = 0U; i < A.size(); i++)
    {
        pre_S += A[i];
        pre_sum[i] = pre_S;
    }
    int sum = 0;
    int end = A.size()-1;

    if (pre_sum[end] > 1000000000)
    {
        sum = -1;
    }
    else 
    {
        for (unsigned int i = 0U; i< A.size(); i++)
        {
            if (A[i] == 0)
            {
                sum += (pre_sum[end] - pre_sum[i]);
            }
        }
    }
   
    if ((sum < -1) || (sum > 1000000000))
    {
        sum = -1;
    }
    return sum;
}
