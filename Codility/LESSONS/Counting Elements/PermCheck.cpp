// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int iPermutation = 1;
    sort(A.begin(), A.end());
    if (A[0] != 1)
    {
        iPermutation = 0;
    }
    else
    {
        for (unsigned int i = 0 ; i < A.size() - 1; i++)
        {
            int iGap = A[i+1] - A[i];
            if ((iGap > 1) || (iGap == 0))
            {
                iPermutation = 0;
                break;
            }
        }
    }
    return iPermutation;    
}
