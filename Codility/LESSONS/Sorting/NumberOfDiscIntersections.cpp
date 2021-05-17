
/*
0, 1
0, 2
0, 4
1, 2
1, 3
1, 4
1, 5
2, 3
2, 4
3, 4
4, 5
*/
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int count = 0;
    int size = static_cast<int>(A.size());
    for (int i = 0U; i< size; i++)
    {
        float low = i-static_cast<float>(A[i]);
        float high = i+static_cast<float>(A[i]);
        for(int j = i+1 ; j < size; j++)
        {
            float sublow = j-static_cast<float>(A[j]);
            float subhigh = j+static_cast<float>(A[j]);

            if((high >= sublow) && (subhigh >= low))
            {
                count++;
                if( count > 10000000)
                {
                    return -1;
                }
            }
        }
    }
    return count;
}

// 아래 방법으로 찾을 수 있도록 처리가 필요
/*
1, 0 
1, 4
1, 2
1, 3
1, 5
4, 0
4, 2
4, 3
4, 5 
2, 0
2, 3
*/

