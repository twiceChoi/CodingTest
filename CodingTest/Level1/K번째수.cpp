#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/* 나의 풀이 */
vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> vTemp;

    for (int i = 0; i < commands.size(); ++i)
    {
        for (int j = commands[i][0] - 1; j <= commands[i][1] - 1; ++j)
        {
            vTemp.emplace_back(array[j]);
        }
        sort(vTemp.begin(), vTemp.end());
        answer.emplace_back(vTemp[commands[i][2] - 1]);
        vTemp.clear();
    }
    return answer;
}
void main()
{
    vector<int> array = { 1, 5, 2, 6, 3, 7, 4 };
    vector<vector<int>> commands = { {2, 5, 3},{4, 4, 1},{1, 7, 3} };
    cout << solution (array,commands )[0] << endl;
    cout << solution(array, commands)[1] << endl;
    cout << solution(array, commands)[2] << endl;
}