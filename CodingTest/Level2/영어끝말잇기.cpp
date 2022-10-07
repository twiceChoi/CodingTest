#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    string s = words[0];
    unordered_set<string> usWords;
    unordered_map<string, int> usWordss;
    usWords.emplace(words[0]); /* 처음 단어 안넣은걸 실수 */
    //words의 인덱스 [i] 는 i % n + 1 번째 사람이 말한 단어이다.

    int i;
    for (i = 1; i < words.size(); ++i)
    {
        if (words[i].size() <= 1)
            break;

        if (s.back() != words[i].front())
            break;


        if (usWords.count(words[i]) != 0) /* 연산자 실수 */
            break;

        usWords.emplace(words[i]); /* emplace_back 실수 */
        s = words[i];
    }

    if (i == words.size())
    {
        answer.emplace_back(0);
        answer.emplace_back(0);
    }
    else
    {
        answer.emplace_back(i % n + 1);
        answer.emplace_back(i / n + 1);
    }

    return answer;
}

void main()
{
   
    vector<string> words;
    words.emplace_back("tank");
    words.emplace_back("kick");
    words.emplace_back("know");
    words.emplace_back("wheel");
    words.emplace_back("land");
    words.emplace_back("dream");
    words.emplace_back("mother");
    words.emplace_back("robot");
    words.emplace_back("tank");

    cout << solution(3, words)[0] << endl;
    cout << solution(3, words)[1] << endl;
}