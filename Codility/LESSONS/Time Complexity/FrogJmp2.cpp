// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int X, int Y, int D) {
    // write your code in C++14 (g++ 6.2.0)
    int maxjump = Y-X;
    int result = 0;
    if(maxjump % D == 0)
    {
        result = maxjump / D;
    }
    else {
        result = (maxjump / D) + 1;
    }
    return result;
}
