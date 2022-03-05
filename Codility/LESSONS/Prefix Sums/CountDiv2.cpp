// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int A, int B, int K) {
    // write your code in C++14 (g++ 6.2.0)
    if (B > 0)
    {
        int totalCount = B/K + 1;
        if (A > 0)
        {
            if (A == B)
            {
                if (A%K == 0)
                    return 1;
                else
                    return 0;
            }
            else
            {
                int subCount = (A-1)/K +1;
                int result = totalCount - subCount;
                return result;
            }
        }
        else
        {
            return totalCount;
        }
    }
    else
    {
        return 1;
    }
}
