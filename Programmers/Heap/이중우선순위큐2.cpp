#include <string>
#include <vector>
#include <queue>

using namespace std;

void pq_main_clear(priority_queue<int,vector<int>>& pq)
{
    priority_queue<int,vector<int>> main_queue;
    swap(pq, main_queue);
}
void pq_max_clear(priority_queue<int,vector<int>, less<>>& pq)
{
    priority_queue<int,vector<int>, less<>> max_queue;
    swap(pq, max_queue);
}
void pq_min_clear(priority_queue<int,vector<int>, greater<>>& pq)
{
    priority_queue<int,vector<int>, greater<>> min_queue;
    swap(pq, min_queue);
}
vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int,vector<int>> main_queue;
    priority_queue<int,vector<int>, less<>> max_queue;
    priority_queue<int,vector<int>, greater<>> min_queue;
    
    for(auto e : operations)
    {
        string szTemp = e;
        string szNum = szTemp.substr(2);
        int num = stoi(szNum);
        switch(szTemp[0])
        {
            case 'I':
                {
                    main_queue.push(num);
                    break;
                }
            case 'D':
                {
                    if (num == 1)
                    {
                        if(!main_queue.empty())
                        {
                            pq_max_clear(max_queue);
                            while(!main_queue.empty())
                            {
                                max_queue.push(main_queue.top());
                                main_queue.pop();
                            }
                            max_queue.pop();
                            while(!max_queue.empty())
                            {
                                main_queue.push(max_queue.top());
                                max_queue.pop();
                            }
                        }
                    }
                    else
                    {
                        if(!main_queue.empty())
                        {
                            pq_min_clear(min_queue);
                            while(!main_queue.empty())
                            {
                                min_queue.push(main_queue.top());
                                main_queue.pop();
                            }
                            min_queue.pop();
                            while(!min_queue.empty())
                            {
                                main_queue.push(min_queue.top());
                                min_queue.pop();
                            }
                        }
                    }
                    break;
                }
            default:
                    break;
        }
    }

    if(main_queue.empty())
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        pq_max_clear(max_queue);
        pq_min_clear(min_queue);
        while(!main_queue.empty())
        {
            max_queue.push(main_queue.top());
            min_queue.push(main_queue.top());
            main_queue.pop();
        }
        answer.push_back(max_queue.top());
        answer.push_back(min_queue.top());
    }
    
    return answer;
}
