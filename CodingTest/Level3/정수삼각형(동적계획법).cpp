#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/* 내풀이 */
int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    vector<vector<int>> vTemp(triangle);
    // 항상 두갈래
    for (int i = 1; i < triangle.size(); ++i)
    {
        for (int j = 0; j < triangle[i].size(); ++j)
        {
            if (j == 0)
                vTemp[i][0] += vTemp[i - 1][0];
            else if (j == triangle[i].size() - 1)
                vTemp[i][j] += vTemp[i - 1][j - 1];
            else
            {
                if (vTemp[i-1][j - 1] < vTemp[i-1][j])
                    vTemp[i][j] += vTemp[i - 1][j];
                else
                    vTemp[i][j] += vTemp[i - 1][j - 1];
            }

        }
    }
    sort(vTemp[triangle.size()-1].begin(), vTemp[triangle.size() - 1].end(), greater<int>());
    return vTemp[triangle.size() - 1][0];
}
void main()
{
    vector<vector<int>> triangle = { {7} ,{3, 8},{8, 1, 0},{2, 7, 4, 4},{4, 5, 2, 6, 5} };

    cout << solution (triangle) << endl;
}