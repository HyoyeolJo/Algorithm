// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    sort(A.begin(), A.end());
    vector<int> B;
    B.assign(1000001, 0);
    int iRet = 1;
    bool bNegative = true;
    for (unsigned int i = 0U; i < A.size() ; i++)
    {
        if (A[i] < 0)
        {
            continue;
        }
        else
        {
            bNegative = false;
            B[A[i]] = 1;
        }
    }

    if (bNegative == true)
    {
        iRet = 1;
    }
    else
    {
        for (unsigned int i = 1U; i < B.size() ; i++)
        {
            if (B[i] == 0)
            {
                iRet = i;
                break;
            }
        }
    }
    return iRet;
}
