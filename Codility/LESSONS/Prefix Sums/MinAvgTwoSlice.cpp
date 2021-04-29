/*
            0 - 6
             27
    0 - 3           4 - 6
      13              14
0 - 1    2 - 3    4 - 5   6
  6        7        6     8
0   1    2   3    4   5
4   2    2   5    1   5
*/

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
int init(int Node, int S, int E, vector<int> &A, vector<int> &B)
{
    if (S == E)
    {
        return B[Node] = A[S];
    }
    int Mid = (S+E)/2;
    return B[Node] = init(Node*2, S, Mid, A, B) + init(Node*2+1, Mid+1, E, A, B);
}
int query(int Node, int S, int E, int L, int R, vector<int> &B)
{
    if (E < L || S > R)
    {     
        return 0;
    }
    if (L <= S && R >= E)
    {
        return B[Node];
    }
    int Mid = (S+E) / 2;
    return query(Node*2, S, Mid, L, R, B) + query(Node*2+1, Mid+1, E, L, R, B);
}
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> B;
    B.assign(A.size()*4, 0);
    int max = init(1,0,A.size()-1, A, B);
    float min  = max / A.size();
    int retX = 0;
    int retY = 6;
    for(unsigned int i = 0U ; i < A.size(); i++)
    {
        for(unsigned int j = i+1; j < A.size(); j++)
        {
            int P = i;
            int Q = j;
            int sum = 0;
            sum = query(1,0,A.size()-1, P, Q, B);
            float fSum = static_cast<float>(sum);
            float fCount = static_cast<float>((Q-P) +1);
            float avg = fSum / fCount;
            if( min > avg)
            {
                min = avg;
                retX = i;
                retY = j;
            }
        }
    }
    
    return retX;
}
