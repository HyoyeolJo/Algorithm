// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int Sum = 0;
    //element only 1
    if( A.size() == 1)
    {
        return A[0];
    }
    // A.size() is even
    if( A.size()%2 == 0)
    {
        return 0;
    }
    sort(A.begin(),A.end());
    for(unsigned int i = 0U; i < A.size(); i++)
    {
        if( i%2 == 0)
            Sum = Sum + A[i];
        else
            Sum = Sum - A[i];
    }

    if( Sum < 0)
        Sum = Sum * (-1);
    return Sum;
}
