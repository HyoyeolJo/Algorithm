#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int max_count = -1;
void DFS (string start, vector<vector<string>> &tickets, vector<string> &answer, vector<string> &temp, vector<bool> &visit,int cnt)
{
    temp.push_back(start);
    if(max_count < cnt)
    {
        max_count = cnt;
        answer = temp;
    }
    for(int i = 0 ; i < tickets.size(); i++)
    {
        if(start == tickets[i][0] && !visit[i])
        {
            visit[i] = true;
            DFS(tickets[i][1],tickets,answer,temp,visit,cnt+1);
            visit[i] = false;
        }
    }
    temp.pop_back();
}
vector<string> solution(vector<vector<string>> tickets) {
    int cnt = 0;
    vector<string> answer;
    vector<string> temp;
    vector<bool> visit(tickets.size(), false);
    sort(tickets.begin(), tickets.end());
    DFS("ICN",tickets,answer,temp,visit,cnt);
    return answer;
}
