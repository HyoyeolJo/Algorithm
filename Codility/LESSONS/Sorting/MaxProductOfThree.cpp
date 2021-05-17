// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    sort(A.begin(), A.end());
    unsigned int end = A.size() - 1U;
    int sumA = A[end]*A[end-1U]*A[end-2U];
    int sumB = A[0]*A[1]*A[end];
    int sum = (sumA < sumB) ? sumB : sumA;
    return sum;
}
