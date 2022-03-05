// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int maxCount = A.size();
    vector<int> checknum(maxCount+1, 0);
    for(auto e : A)
    {
        if (e <= A.size())
        {
            if (checknum[e] == 0)
            {
                maxCount--;
                checknum[e] = 1;
            }
            if (maxCount == 0)
            {
                return 1;
            }
        }

    }
    return 0;
}
