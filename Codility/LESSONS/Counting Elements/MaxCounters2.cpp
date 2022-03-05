// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(int N, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> counter(N,0);
    int maxCounter = 0;
    int saveMaxCounter= 0;
    for (auto e : A)
    {
        if (1 <= e && e <= N)
        {
            if (counter[e-1] < saveMaxCounter)
                counter[e-1] = saveMaxCounter;
            counter[e-1]++;
            if(maxCounter < counter[e-1])
                maxCounter = counter[e-1];
        }
        else if (e == (N+1))
        {
            saveMaxCounter = maxCounter;
        }
       
    }
    for (unsigned int i = 0U ; i < counter.size(); i++)
    {
        if (saveMaxCounter > counter[i])
                counter[i] = saveMaxCounter;
    }

    return counter;
}
