// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(int N, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int>B;
    B.assign(N,0);
    int iMax = 0;
    int iMaxCounter = 0;
  
    for (unsigned int i = 0U; i < A.size(); i++)
    {
        if (A[i] <= N)
        {
            if (B[A[i]-1] < iMaxCounter)
            {
                B[A[i]-1] = iMaxCounter;
            }
            B[A[i]-1]++;
            
            if (iMax < B[A[i]-1])
            {
                iMax = B[A[i]-1];
            }
        }
        // A[i] == N+1
        else
        {
            if (iMax > 0)
            {
                iMaxCounter = iMax;
            }
        }
    }

    for (unsigned int i = 0U; i< B.size(); i++)
    {
        if (iMaxCounter > 0)
        {
            if (B[i] < iMaxCounter)
            {
                B[i] = iMaxCounter;
            }
        }
    }
    return B;
}
