// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    vector<long>lower;
    vector<long>upper;
    long i = 0;
    for(auto e : A)
    {
        long temp = static_cast<long>(e);
        lower.push_back(i-temp);
        upper.push_back(i+temp);
        i++;
    }
    sort(lower.begin(),lower.end());
    sort(upper.begin(),upper.end());
    
    int count = 0;
    int j = 0;
    int size = static_cast<int>(lower.size());
    for(int i = 0; i < size; i++)
    {
        for(; j < size; j++)
        {
            if(lower[j] <= upper[i])
            {
                count+=j;
                count-=i;
            }
            else
            {
                break;
            }
        }
    }

    if(count > 10000000)
        count = -1;
    return count;
}
