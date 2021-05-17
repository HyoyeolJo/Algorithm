// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    sort(A.begin(), A.end());
    int sum = 0;
    int preValue = -1000001;
    for (unsigned int i = 0U; i < A.size(); i++)
    {
        if (preValue != A[i])
        {
            sum++;
            preValue = A[i];
        }
    }
    return sum;
}
