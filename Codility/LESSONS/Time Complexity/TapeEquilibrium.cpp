// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int iLeftSum = 0;
    int iRightSum = 0;
    int iMin = 0;
    int iAbsSum = 0;
    //P = 1
    iLeftSum = A.front();
    for (unsigned int i = 1U ; i < A.size(); i++)
        iRightSum = iRightSum + A[i];
    iAbsSum = iLeftSum - iRightSum;
    if (iAbsSum < 0)
    {
        iAbsSum = iAbsSum * (-1);
    }
    iMin = iAbsSum;

    // P > 1
    for (unsigned int i = 0U ; i < A.size() - 2U ; i++)
    {
        iLeftSum = iLeftSum + A[i+1];
        iRightSum = iRightSum - A[i+1];
        iAbsSum = iLeftSum - iRightSum;
        if (iAbsSum < 0)
        {
            iAbsSum = iAbsSum * (-1);
        }
        if (iMin > iAbsSum)
            iMin = iAbsSum;
    }
    return iMin;
}
