// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

//example A[5] = {0, 1, 0, 1, 1}
//P Q P Q Q
//0 1 2 3 4
//P < Q : {0,1},{0,3},{0,4},{2,3},{2,4} => 5

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    unsigned int sum = 0U;
    unsigned int Qtotal = 0U;
    for(auto e : A)
    {
        if(e == 1)
            Qtotal++;
    }
    for(auto e : A)
    {
        if(e == 0)
        {
            sum += Qtotal;
        }
        else
        {
            Qtotal--;
        }
    }
    if(sum > 1000000000)
        sum = -1;
    return sum;
}
