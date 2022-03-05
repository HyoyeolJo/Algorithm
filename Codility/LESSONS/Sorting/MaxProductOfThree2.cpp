// you can use includes, for example:
 #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    sort(A.begin(),A.end());
    int last = A.size()-1;
    // negative * negative * nevative
    // negative * negative * positive
    int resultA = A[0]*A[1]*A[A.size()-1];
    // positive * positive * positive
    int resultB = A[last]*A[last-1]*A[last-2];
    return (resultA > resultB) ? resultA : resultB;
}
