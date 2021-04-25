// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int A, int B, int K) {
    // write your code in C++14 (g++ 6.2.0)

    int iPreCount = 0;
    int iPostCount = 0;
    int iPreNum = A-1;
    int iPostNum = B;
    int iRet = 0;

    iPreCount = (iPreNum / K) + 1;
    iPostCount = (iPostNum / K) + 1;
    
    if (A == 0)
    {
        iPreCount = 0;
    }
    
    iRet = iPostCount - iPreCount;
    return iRet;
}
