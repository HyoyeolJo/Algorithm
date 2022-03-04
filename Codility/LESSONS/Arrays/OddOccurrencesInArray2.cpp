// you can use includes, for example:
// #include <algorithm>
#include <unordered_map>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    std::unordered_map<int, int>num;
    for (auto e : A)
    {
        num[e]++;
    }
    for (auto ee : num)
    {
        if (ee.second %2 != 0)
        {
            return ee.first;
        }
    }
}
