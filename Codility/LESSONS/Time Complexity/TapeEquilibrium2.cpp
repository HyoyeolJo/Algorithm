// you can use includes, for example:
// #include <algorithm>
#include <iostream>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int rightsum = 0;
    int leftsum = 0;
    for (auto e : A)
    {
        rightsum+=e;
    }
    int P = 1;
    int nMin = 0;
    for (auto ee : A)
    {
        leftsum += ee;
        rightsum -= ee;
        int abssum = leftsum - rightsum;
        if(abssum < 0)
            abssum*=-1;
        if (P == 1)
        {
            nMin = abssum;
        }
        else if ( P == A.size())
        {
            break;
        }
        else
        {
            if (nMin > abssum)
            {
                nMin = abssum;
            }
        };
        P++;
    }
    return nMin;
}
