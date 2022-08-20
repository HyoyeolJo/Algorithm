#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, M;
	vector<string>roomName; // 회의실 이름
	map<string,vector<int>>reserveRoom; // 배정된 회의실 점유시간
	map<string,vector<string>>avilableRoomTime; // 회의실 예약가능시간
	cin>>N>>M;
	for(int i = 0 ; i < N ; i++)
	{
		string temp;
		cin>>temp;
		roomName.push_back(temp);
		vector<int>timeset(20,0);
		reserveRoom[temp]=timeset;
		reserveRoom[temp][8] = 1;
		reserveRoom[temp][18] = 1;
		avilableRoomTime[temp];
	}
	
	for(int i = 0 ; i < M ; i++)
	{
		string temp;
		int startTime, endTime;
		cin>>temp>>startTime>>endTime;
		for(int j  = startTime ; j < endTime; j++)
		{
			reserveRoom[temp][j] = 1;
		}

	}
	sort(roomName.begin(), roomName.end());
	// 룸별로 이용가능시간 정리
	for (auto e : roomName)
	{
		int start = 0;
		int end = 0;
		for(int i = 9 ; i <=18; i++)
		{
			if(reserveRoom[e][i] == 0 && start == 0)
			{
				start = i;
			}
			else if(start > 0 && reserveRoom[e][i] == 1)
			{
				end = i;
				string starttime;
				string endtime;
				string availtime;
				if(start == 9)
					starttime = "09";
				else
					starttime = to_string(start);
				if(end == 9)
					endtime = "09";
				else
					endtime = to_string(end);
				availtime = starttime + "-" + endtime;
				avilableRoomTime[e].push_back(availtime);
				start = 0;
				end = 0;
			}
		}
		cout<<endl;
	}
	// 결과 출력
	
	for (int i = 0; i < roomName.size(); i++)
	{
		cout<<"Room "<<roomName[i]<<":"<<endl;
		if(avilableRoomTime[roomName[i]].size() > 0){
				cout<<avilableRoomTime[roomName[i]].size()<<" available:"<<endl;
				for(auto e: avilableRoomTime[roomName[i]])
				{
					cout<<e<<endl;
				}
		}
		else{
			cout<<"Not available"<<endl;
		}

		if(i != roomName.size()-1)
			cout<<"-----"<<endl;
	}
	
	return 0;
}
