// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int X, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> B;
    B.assign(A.size()+1,0);
    int iSum = 0;
    int iRet = -1;
    for(unsigned int i = 0U ; i< A.size(); i++)
    {
        if(B[A[i]] == 0)
        {
            if( A[i] <= X)
            {
                iSum++;
            }
            B[A[i]] = 1;
        }
        if (iSum == X)
        {
            iRet = i;
            break;
        }
    }
    return iRet;
}
