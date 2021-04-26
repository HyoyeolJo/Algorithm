// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

/*
                             1
                           [0-6]
                    2                   3
                  [0-3]               [4-6]
               4         5          6       7
             [0-1]     [2-3]      [4-5]   [6-6]
             8    9    10   11   12   13
           [0-0][1-1][2-2][3-3] [4-4][5-5]
*/
#define MAXINF    60000
int minQuery(int node, int s, int e, int l, int r, vector<int> &C)
{
    // No Bound
    if (e < l || s > r)
    {
        return MAXINF;
    }
    // Catch Find
    if( s >= l && e <= r)
    {
        return C[node];
    }
    int mid = (s + e) / 2;
    int iMin = min(minQuery(2 * node, s, mid, l,r,C), minQuery((2 * node) + 1, mid + 1, e, l, r, C));
    return iMin;
}
int init(int node, int s, int e, vector<int> &B, vector<int> &C)
{
    //reaf node
    if (s == e)
    {
        C[node] = B[s];
        return C[node];
    }
    //else node
    int mid = (s + e) / 2;
    C[node] = min(init(2 * node, s, mid, B, C), init((2 * node) + 1, mid + 1, e, B, C));
    return C[node];
}
vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    // write your code in C++14 (g++ 6.2.0)
    
    // string to int
    vector<int> B;
    for (unsigned int i  = 0U; i< S.size(); i++)
    {
            int iNucleotide = S[i]-'A';
            switch(iNucleotide)
            {
            // A
            case 0:
                iNucleotide = 1;
                break;
            // C
            case 2:
                iNucleotide = 2;
                break;
            // G
            case 6:
                iNucleotide = 3;
                break;
            // T
            case 19:
                iNucleotide = 4;
                break;
            default:
                iNucleotide = 0;
                break;
            }
            B.push_back(iNucleotide);
    }
    // segment Tree
    vector<int> C;
    //4*N
    C.assign(B.size()*4, 0);
    init (1, 0, B.size()-1, B, C);

    vector<int>D;
    for (unsigned int i  = 0u; i < P.size() ; i++)
    {
         int iRet = minQuery(1, 0, B.size()-1, P[i], Q[i], C);
         D.push_back(iRet);
    }
   
    return D;
}
