// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int iSum = 0;
    //element only 1
    if( A.size() == 1U)
    {
        return A[0];
    }
    // A.size() is even
    if( A.size()%2U == 0U)
    {
        return 0;
    }
    sort(A.begin(),A.end());
    for(unsigned int i = 0U; i < A.size(); i++)
    {
        if( i%2U == 0U)
            iSum = iSum + A[i];
        else
            iSum = iSum - A[i];
    }

    if( iSum < 0)
        iSum = iSum * (-1);
    return iSum;
}
