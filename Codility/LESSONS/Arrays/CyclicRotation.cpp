// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(vector<int> &A, int K) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> B;
    unsigned int iIndex = static_cast<unsigned int>(K) % A.size(); // 0 equals K
    
    // A size -> 0
    if (A.size() == 0U)
    {
        return A;
    }

    // A all Index -> 0
    if (iIndex == 0U)
    {
        return A;
    }
    
    unsigned int nBound = A.size() - iIndex;
    for (unsigned int i = nBound; i < A.size(); i++)
    {
        B.push_back(A[i]);
    }
    for (unsigned int j = 0U; j < nBound; j++)
    {
        B.push_back(A[j]);
    }

    return B;
}
