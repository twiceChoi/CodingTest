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
    usWords.emplace(words[0]); /* ó�� �ܾ� �ȳ����� �Ǽ� */
    //words�� �ε��� [i] �� i % n + 1 ��° ����� ���� �ܾ��̴�.

    int i;
    for (i = 1; i < words.size(); ++i)
    {
        if (words[i].size() <= 1)
            break;

        if (s.back() != words[i].front())
            break;


        if (usWords.count(words[i]) != 0) /* ������ �Ǽ� */
            break;

        usWords.emplace(words[i]); /* emplace_back �Ǽ� */
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