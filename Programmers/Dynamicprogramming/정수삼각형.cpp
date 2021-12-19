#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<vector<int>> temp;
    temp = triangle;
    int max = -1;
    /*
    temp[0][0] = triangle[0][0];
    
    temp[1][0] = triangle[1][0] + temp[0][0];
    temp[1][1] = triangle[1][1] + temp[0][0];
    
    temp[2][0] = triangle[2][0] + temp[1][0];
    temp[2][1] = max(triangle[2][1] + temp[1][0], triangle[2][1] + temp[1][1]);
    temp[2][2] = triangle[2][2] + temp[1][1];
    
    temp[3][0] = triangle[3][0] + temp[2][0];
    temp[3][1] = max(triangle[3][1] + temp[2][0], triangle[3][1] + temp[2][1]);
    temp[3][2] = max(triangle[3][2] + temp[2][1], triangle[3][2] + temp[2][2]);
    temp[3][3] = triangle[3][3] + temp[2][2];
    
    temp[4][0] = triangle[4][0] + temp[3][0];
    temp[4][1] = max(triangle[4][1] + temp[3][0], triangle[4][1] + temp[3][1]);
    temp[4][2] = max(triangle[4][2] + temp[3][1], triangle[4][2] + temp[3][2]);
    temp[4][3] = max(triangle[4][3] + temp[3][2], triangle[4][3] + temp[3][3]);
    temp[4][4] = triangle[4][4] + temp[3][3];
    */
    for(int i = 0; i< temp.size();i++)
    {
        for(int j = 0; j < temp[i].size();j++)
        {
            if( j == 0)
            {
                temp[i][j] = triangle[i][j];
                if( i > 0)
                {
                    temp[i][j] += temp[i-1][j];
                }
                    
            }
            else if ( j == i)
            {
                temp[i][j] = triangle[i][j];
                if( i > 0 & j > 0)
                {
                    temp[i][j] += temp[i-1][j-1];
                }
            }
            else
            {
                if(i > 0 && j > 0)
                {
                    int max1 = triangle[i][j] + temp[i-1][j-1];
                    int max2 = triangle[i][j] + temp[i-1][j];
                    if( max1 > max2)
                        temp[i][j] = max1;
                    else
                        temp[i][j] = max2;
                }
            }
            // 최대값
            if( max <= temp[i][j])
                max = temp[i][j];
        }
    }
    
    return answer = max;
}
