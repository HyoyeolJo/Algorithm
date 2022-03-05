// you can use includes, for example:
// #include <algorithm>
#include <map>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
int initQuery(string &S, vector<int> &tree, int node, int start, int end, map<char,int> &DNA)
{
    if(start == end)
    {
        return tree[node] = DNA[S[start]];
    }
    int mid = (start+end)/2;
    return tree[node] = min(initQuery(S, tree, node*2, start, mid, DNA),
    initQuery(S, tree, node*2+1, mid+1, end, DNA));
}

int requestQuery(vector<int> &tree, int node, int start, int end, int left, int right)
{
    // No Bound
    if ((end < left) || (start > right))
    {
        return 1000001;
    }
    //Hit
    if((left <= start) && (right >= end))
    {
        return tree[node];
    }

    int mid = (start+end)/2;
    return min(requestQuery(tree, node*2, start, mid, left, right),
    requestQuery(tree, node*2+1, mid+1, end, left, right));
}
vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> result;
    map<char,int>DNA = {{'A',1},{'C',2},{'G',3},{'T',4}};
    vector<int>tree;
    tree.assign(S.length()*4, 0);
    int end = S.length()-1;
    (void)initQuery(S, tree, 1, 0, end, DNA);
    for(unsigned int i = 0U ; i < P.size(); i++)
    {
        int left = P[i];
        int right = Q[i];
        int nMin = requestQuery(tree, 1, 0, end, left, right);
        result.push_back(nMin);
    }
    return result;
}
