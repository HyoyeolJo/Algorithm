// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int X, int Y, int D) {
    // write your code in C++14 (g++ 6.2.0)
    //X + nD <= Y
    //n <= (Y-X) / D;
    int iRet = 1;
    if (X <= Y)
    {
        iRet = (Y-X) / D;
        if (((Y-X) % D) != 0)
            iRet++;
    }
    return iRet;
}
