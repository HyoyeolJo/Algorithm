// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    int Temp = N;
    int Sum = 0;
    int Max = 0;
    bool Set = false;
    while(Temp != 0)
    {
        int Binary = Temp%2;
        if (Binary == 1)
        {
            Set = true;            
            if (Temp != 1)
                {
                    Sum = 0;
                } 
        }
        else
        {
            if( Set == true)
            {
                Sum++;
                if (Max < Sum)
                {
                   Max = Sum;
                }
            }
             
        }
        Temp = Temp/2; 
    }
    return Max;
}
