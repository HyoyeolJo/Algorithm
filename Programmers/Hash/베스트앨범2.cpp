#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool compare (pair<string, int> a, pair<string, int> b)
{
    return a.second > b.second;
}
bool compare2 (pair<int, int> a, pair<int, int> b)
{
    //재생수 같으면 고유번호가 작은게 우선
    if(a.first == b.first)
    {
        return a.second < b.second;
    }
    return a.first > b.first;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string,int>tablesum;
    map<string,vector<pair<int,int>>>table;
    
    for(int i = 0 ; i < genres.size(); i++)
    {
        tablesum[genres[i]]+=plays[i];
        table[genres[i]].push_back(make_pair(plays[i],i));
    }
    
    vector<pair<string,int>> v (tablesum.begin(),tablesum.end());
    sort(v.begin(), v.end(), compare);
    for(auto e : v)
    {
        vector<pair<int,int>> temp = table[e.first];
        sort(temp.begin(), temp.end(), compare2);
        int i = 0;
        for(auto e : temp)
        {
            if(i < 2)
            {
                answer.push_back(e.second);
                i++;
            }
            else
            {
                break;
            }
        }
    }
    
    return answer;
}
