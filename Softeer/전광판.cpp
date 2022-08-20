#include<iostream>
#include <vector>
#include <string>


using namespace std;
int crosscheck(int A, int B, int digitA, int digitB)
{
	// none, 0, 1, 2, 3, 4, 5, 6, 7 ,8 ,9
	vector<vector<int>> numberset = {{1,1,1,0,1,1,1}, // 0
							 		 {0,0,1,0,0,1,0}, // 1
							 		 {1,0,1,1,1,0,1}, // 2
							 		 {1,0,1,1,0,1,1}, // 3
							 		 {0,1,1,1,0,1,0}, // 4
							 		 {1,1,0,1,0,1,1}, // 5
							 		 {1,1,0,1,1,1,1}, // 6
							 		 {1,1,1,0,0,1,0}, // 7
							 		 {1,1,1,1,1,1,1}, // 8
							 		 {1,1,1,1,0,1,1}, // 9
							 		 {0,0,0,0,0,0,0}};// NONE
	int cnt = 0;
	if (digitA <= 0)
		A = 10;
	if (digitB <= 0)
		B = 10;
	for(int i = 0 ; i < 7 ; i++)
	{
		if(numberset[A][i] != numberset[B][i])
			cnt++;
	}
	return cnt;
}
int check(int A, int B)
{
	int diffcnt = 0;
	string sA = to_string(A);
	string sB = to_string(B);
	int digitA = sA.length();
	int digitB = sB.length();
	while(digitA > 0 || digitB > 0)
	{
		int tempnumA = A%10;
		int tempnumB = B%10;
		
		diffcnt+=crosscheck(tempnumA, tempnumB, digitA, digitB);
		digitA--;
		digitB--;
		A/=10;
		B/=10;
	}
	return diffcnt;
}
int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int testcase;
	int A, B;
	cin>>testcase;
	int ret;
	for(int i = 0 ; i < testcase ; i ++)
	{
		cin>>A>>B;
		ret = check(A,B);
		cout<<ret<<endl;
	}
	
	return 0;
}
