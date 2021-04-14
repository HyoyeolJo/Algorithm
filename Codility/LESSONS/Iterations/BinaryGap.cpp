// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    int iTemp = N;
    int iSum = 0;
    int iMax = 0;
    bool bSet = false;
    while(iTemp != 0)
    {
        int iBinary = iTemp%2;
        if (iBinary == 1)
        {
            bSet = true;            
            if (iTemp != 1)
                {
                    iSum = 0;
                } 
        }
        else
        {
            if (iSet == true)
            {
                iSum++;
                if (iMax < iSum)
                {
                   iMax = iSum;
                }
            }
             
        }
        iTemp = iTemp/2; 
    }
    return iMax;
}
