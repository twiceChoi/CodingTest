#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

/* 내 풀이 */
vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    unordered_map<char, vector<string>>umWords;

    for (int i = 0; i < strings.size(); ++i)
    {
        umWords[strings[i][n]].push_back(strings[i]);
    }

    for (char i = 'a'; i <= 'z'; ++i)
    {
        if (umWords[i].size() == 1)
            answer.emplace_back(umWords[i][0]);
        else if (umWords[i].size() <= 0)
            continue;
        else
        {
            sort(umWords[i].begin(),umWords[i].end());
            for (int j = 0; j < umWords[i].size(); ++j)
            {
                answer.emplace_back(umWords[i][j]);
            }
        }
    }
    return answer;
}

void main()
{
    vector<string> strings;
    strings.push_back("sun");
    strings.push_back("bed");
    strings.push_back("car");
    int n = 1;
    cout << solution(strings, n)[0] << endl;
    cout << solution(strings, n)[1] << endl;
    cout << solution(strings, n)[2] << endl;
}

/* 참고 코드 */
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int i;

bool compare(string a, string b) {
    return a[i] == b[i] ? a < b : a[i] < b[i];
}

vector<string> solution(vector<string> strings, int n) {
    i = n;
    sort(strings.begin(), strings.end(), compare);
    return strings;
}