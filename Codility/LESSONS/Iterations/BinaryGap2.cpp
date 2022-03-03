// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    int iCnt = 0;
    int iMaxcnt = 0;
    bool bOpen = false;
    while (N != 0)
    {
        if (N % 2 == 0)
        {
            if(bOpen == true)
            {
                iCnt++;
            }
        }
        else
        {
            bOpen = true;
            if (iMaxcnt < iCnt)
            {
                iMaxcnt = iCnt;
            }
            iCnt = 0;
        }
        N=N/2;
    }
    return iMaxcnt;
}
