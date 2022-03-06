// you can use includes, for example:
// #include <algorithm>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A, vector<int> &B) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int>checkfish;
    int count = 0;
    for(unsigned int i = 0U ; i < A.size(); i++)
    {
        if(B[i] == 0)
        {
            if(checkfish.size() == 0)
            {
                count++;
            }
            else
            {
                while(checkfish.size() > 0)
                {
                    if( checkfish.back() < A[i])
                    {
                        checkfish.pop_back();
                        if(checkfish.size() == 0)
                        {
                            count++;
                        }
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        else {
            checkfish.push_back(A[i]);
        }
    }
    return count + checkfish.size();
}
