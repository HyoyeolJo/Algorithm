// you can use includes, for example:
// #include <algorithm>
#include <vector>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    vector<char>stackitem;
    for(unsigned int i = 0 ; i < S.length(); i++)
    {
        if(S[i] == '{' ||
        S[i] == '[' ||
        S[i] == '(')
            stackitem.push_back(S[i]);
        else
        {
            if(stackitem.size() == 0 )
                return 0;
            char temp = stackitem.back();
            switch(temp)
            {
                case '{' :
                {
                    if(S[i] == '}')
                    {
                        stackitem.pop_back();
                    }
                    else {
                        return 0;
                    }
                    break;
                }
                case '[' :
                {
                    if(S[i] == ']')
                    {
                        stackitem.pop_back();
                    }
                    else {
                        return 0;
                    }
                    break;
                }
                case '(' :
                {
                    if(S[i] == ')')
                    {
                        stackitem.pop_back();
                    }
                    else {
                        return 0;
                    }
                    break;
                }
            }  
        }
    }
    if(stackitem.size() > 0)
    {
        return 0;
    }
    else {
        return 1;
    }
}
