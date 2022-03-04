// you can use includes, for example:
// #include <algorithm>
#include <map>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int X, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    std::map<int, bool> leaf;
    for (int i = 1; i <=X ; i++)
        leaf[i] = true;
    int count = 0;
    for (auto e : A)
    {
        if (leaf[e] == true)
        {
            X--;
            leaf[e] = false;
        }

        if (X == 0)
        {
            return count;
        }
        count++;
    }
    return -1;
}
