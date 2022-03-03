// you can use includes, for example:
// #include <algorithm>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(vector<int> &A, int K) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> nRet;
    if(A.size() == 0U)
    {
        return A;
    }
    else
    {
        unsigned int uRound = static_cast<unsigned int>(K)%A.size();
        if(uRound == 0U)
        {
            return A;
        }
        else
        {
            unsigned int uStart = A.size() - uRound;
            for(unsigned int i = uStart ; i < A.size(); i++)
            {
                nRet.push_back(A[i]);
            }
            for(unsigned int i = 0U ; i < uStart; i++)
            {
                nRet.push_back(A[i]);
            }
        }
    }


    return nRet;
}
