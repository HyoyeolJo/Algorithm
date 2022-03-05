// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    if(A.size() < 3)
        return 0;

    sort(A.begin(), A.end());
    for(unsigned int i = 0U ; i < A.size()-2U ; i++)
    {
        long P = A[i];
        long Q = A[i+1U];
        long R = A[i+2U];
        if( P + Q > R && Q + R > P && R + P > Q)
            return 1;
    }
    return 0;
}
