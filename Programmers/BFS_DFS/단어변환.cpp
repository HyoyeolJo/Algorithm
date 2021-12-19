#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
int nMin  = -1;
unordered_map<string, int> word;
void dfs(string begin, string target, int count)
{
    if( begin.compare(target)  == 0)
    {
        if( nMin == -1)
        {
            nMin = count;
        }
        else
        {
            if (nMin > count)
                nMin = count;
        }
        return;
    }
    
    for(auto e : word)
    {
        if(e.second != 1 && begin.compare(e.first) != 0)
        {
            int ccount = 0;
            for(int i = 0 ; i < begin.length(); i++)
            {
                string temp = e.first;
                if(begin[i] != temp[i])
                    ccount++;
            }
            if( ccount == 1)
            {
                word[e.first] = 1;
                ++count;
                dfs(e.first, target, count);
                break;
            }
        }
    }
}
int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    for(auto e : words)
    {
        word.insert(make_pair(e,0));
    }
    if(word.find(target) != word.end())
    {
        dfs(begin, target, 0);
        if( nMin != -1)
            answer = nMin;
        else
            answer = 0;
    }
    else
    {
        answer = 0;
    }
    return answer;
}
