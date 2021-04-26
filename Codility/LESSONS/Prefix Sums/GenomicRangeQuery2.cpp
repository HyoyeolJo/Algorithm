// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#define MAXINT  50001
vector<int> stringtoint(string &S)
{
    vector<int> IntS;
    for(unsigned int i = 0U; i < S.size(); i++)
    {
        switch(S[i])
        {
        case 'A':
            IntS.push_back(1);
        break;
        case 'C':
            IntS.push_back(2);
        break;
        case 'G':
            IntS.push_back(3);
        break;
        case 'T':
            IntS.push_back(4);
        break;
        default:
            // Do Nothing
        break;
        }
    }
    return IntS;
}

int init (int NODE, int Start, int End, vector<int> & DNA, vector<int> & BINARY)
{
    if (Start == End)
    {
        BINARY[NODE] = DNA[Start];
        return BINARY[NODE];
    }
    int Mid = (Start + End) / 2;
    BINARY[NODE] = min(init(NODE*2, Start, Mid, DNA, BINARY), 
    init(NODE*2+1, Mid+1, End, DNA, BINARY));
    return BINARY[NODE];
}
int globalMIN = 50001;
void query (int NODE, int Start, int End, int Left, int Right, vector<int> & BINARY)
{
    // No Bound
    if (End < Left || Start > Right)
    {
        return;
    }

    if (Left <= Start && Right >= End)
    {
        globalMIN = min(globalMIN, BINARY[NODE]);
        return;
    }
    int Mid = (Start+End) / 2;
    query(NODE*2, Start, Mid, Left, Right, BINARY);
    query(NODE*2+1, Mid+1, End, Left, Right, BINARY);
}
vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> DNA(stringtoint(S));
    // 0 - 6
    int end = static_cast<int>(DNA.size()) -1;
    vector<int> BINARY(DNA.size() * 4);
    init(1, 0, end, DNA, BINARY);
    vector<int> RET;
    for (unsigned int i = 0U; i < P.size(); i++)
    {
        query(1, 0, end, P[i], Q[i], BINARY);
        RET.push_back(globalMIN);
        globalMIN = MAXINT;
    }
    return RET;
}
