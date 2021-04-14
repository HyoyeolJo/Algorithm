// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int iRet = 0;
    if (A.size() == 0U)
    {
        iRet = 1;
    }
    else if (A.size() == 1U)
    {
        if( A[0] == 1)
        {
            iRet = 2;
        }
        else //A[0] == 2
        {
            iRet = 1;
        }
    }
    else
    {
        sort(A.begin(),A.end());
        bool bConnect = true;
        for(unsigned int i = 0U; i<A.size();i++)
        {
            if((A[i] - i) == 2)
            {
                bConnect = false;
                iRet = i+1;
                break;
            }
        }
        if (bConnect == true)
            iRet = A.size()+1;
    }
    return iRet;
}
