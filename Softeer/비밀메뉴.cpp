#include<iostream>
#include<string>

using namespace std;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int M,N,K;
	cin>>M>>N>>K;
	string hiddenNumset;
	for(int i = 0 ; i < M ; i++)
	{
		int hiddenNum;
		cin>>hiddenNum;
		hiddenNumset+=to_string(hiddenNum);
	}
	string controlButton;
	for(int i = 0 ; i < N ; i ++)
	{
		int button;
		cin>>button;
		controlButton+=to_string(button);
	}

	int hiddennumcount = hiddenNumset.length();
	int controlbuttoncount = controlButton.length();

	if(hiddennumcount <= controlbuttoncount)
	{
		for(int i = 0 ; i < controlbuttoncount-hiddennumcount+1; i++)
		{
			string temp = controlButton.substr(i,hiddennumcount);
			if(hiddenNumset.compare(temp) == 0)
			{
				cout<<"secret";
				return 0;
			}
		}
	}
	cout<<"normal";
	return 0;
}
