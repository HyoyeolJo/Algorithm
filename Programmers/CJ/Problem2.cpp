#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
int mincount = 0;
//count : 환승횟수
vector<int>visit(1000000,0);
void dfs(int start, int end, int line, vector<unordered_map<int, int>> &subwaymap, int count)
{
    count++;
    if(start == end)
    {
        if(mincount == 0)
        {
            mincount = count;
        }
        else if (mincount > count)
        {
            mincount = count;
        }
        return;
    }
    //find end
    if(subwaymap[line].find(end) != subwaymap[line].end())
    {
        if(count > 0)
        {
            start = end;
            dfs(start, end, line, subwaymap, count);
        }
    }
    
    //가까운 환승역 찾기
    for(auto e : subwaymap[line])
    {
        for(int j = 0 ; j < subwaymap.size() ; j++)
        {
            if( j != line)
            {
                if(visit[e.first] != 1)
                {
                    if (subwaymap[j].find(e.first) != subwaymap[j].end())
                    {
                        visit[e.first] = 1;
                        //find start line : i
                        dfs(e.first, end, j, subwaymap, count);
                        count--;
                        visit[e.first] = 0;
                    } 
                }

            }
        }
    }
    count--;
    visit[start] = 0;
}
int solution(vector<string> &subway, int start, int end) {
    int answer = 0;
    //노선별 역 저장하기
    vector<unordered_map<int, int>>subwaymap(subway.size());
    for(int i = 0; i < subway.size(); i++)
    {
        string temp = subway[i];
        int start = 0;
        for(int j = 0 ; j < temp.size(); j++)
        {
            if(temp[j] == ' ')
            {
                string node = temp.substr(start, j-start);
                start = j+1;
                subwaymap[i].insert(make_pair(stoi(node),stoi(node)));
            }
        }
        string lastnode = temp.substr(start, temp.length()-start);
        subwaymap[i].insert(make_pair(stoi(lastnode),stoi(lastnode)));
    }
    
    //찾을 역 확인
    int count = -1;
    for(int i = 0 ; i < subwaymap.size(); i++)
    {
        if (subwaymap[i].find(start) != subwaymap[i].end())
        {
            //find start line : i
            visit[start] = 1;
            dfs(start, end, i, subwaymap, count);
            break;
        }
    }
    
    answer = mincount;
    return answer;
}
