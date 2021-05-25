// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int count = 0;
    int size = static_cast<int>(A.size());
    vector<float>lower;
    vector<float>upper;
    for (int i = 0U; i< size; i++)
    {
        float low = i-static_cast<float>(A[i]);
        float high = i+static_cast<float>(A[i]);
        lower.push_back(low);
        upper.push_back(high);
    }
    sort(lower.begin(),lower.end());
    sort(upper.begin(),upper.end());
    int j = 0;
    for (int i = 0U; i< size; i++)
    {
        for (; j < size; j++)
        {
            if (lower[j] <= upper[i])
            {
                count += j;
                count -= i;
            }
            else {
                break;
            }
        }
    }
    if (count > 10000000)
    {
        count = -1;
    }
    return count;
}
