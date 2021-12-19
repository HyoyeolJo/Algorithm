#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;
bool comscore(pair<string,int> a, pair<string, int> b)
{
    return a.second > b.second;
}
bool complay(pair<int,int> a, pair<int, int> b)
{
    return a.first > b.first;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int>favorite;
    vector<pair<string, int>>vfavorite;
    map<string, vector<pair<int, int>>>tables;
    
    for(int i = 0; i < genres.size(); i++)
    {
        favorite[genres[i]]+=plays[i];
        tables[genres[i]].push_back(make_pair(plays[i],i));
    }
    
    vfavorite.assign(favorite.begin(), favorite.end());
    sort(vfavorite.begin(),vfavorite.end(), comscore);
    
    for(auto &e : tables)
    {
        sort(e.second.begin(), e.second.end(), complay);
    }
    
    for(auto ee : vfavorite)
    {
        string temp = ee.first;
        for(int i = 0 ; i < tables[temp].size() && i < 2 ; i++)
        {
            answer.push_back(tables[temp][i].second);
        }
    }

    return answer;
}
