#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int, vector<int>, less<int>> pq;
    for(auto e : operations)
    {
        string temp = e;
        string tempnum = temp.substr(2,temp.length()-1);
        int iNum = stoi(tempnum);
        switch(temp[0])
        {
            case 'I':
                {
                    pq.push(iNum);
                }
                break;
            case 'D':
                {
                    // delete min
                    if(iNum == -1)
                    {
                        if(pq.size() == 1)
                        {
                            pq.pop();
                        }
                        else if (pq.size() > 1)
                        {
                            vector<int>tempset;
                            //resize
                            int count = 0;
                            int maxlen = pq.size();
                            while(!pq.empty()){
                                if(count < maxlen-1)
                                    tempset.push_back(pq.top());
                                pq.pop();
                                count++;
                            }
                            for(auto eee : tempset)
                            {
                                pq.push(eee);
                            }
                        }
                    }
                    // delete max
                    else // iNum == 1
                    {
                        if(pq.size() > 0)
                        {
                            pq.pop();
                        }
                    }
                }
                break;
        }
    }
    if( pq.size() == 0)
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else if (pq.size() == 1)
    {
        answer.push_back(pq.top());
        answer.push_back(pq.top());
    }
    else
    {
        int imax = 0;
        int imin = 0;
        int len = pq.size();
        int count = 0;
        while(!pq.empty())
        {
            if(count == 0)
            {
                imax = pq.top();
            }
            else if(count == len-1)
            {
                imin = pq.top();
            }
            count++;
            pq.pop();
        }
        answer.push_back(imax);
        answer.push_back(imin);
    }
    return answer;
}
