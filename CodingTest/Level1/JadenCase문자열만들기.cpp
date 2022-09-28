#include <string>
#include <vector>
#include <iostream>

using namespace std;
/* ���ڵ� */
string solution(string s) {
    string answer = s;

    for (int i = 0; i < s.size(); ++i)
    {
        if (answer[i] == ' ')
            continue;

        if (i != 0 && answer[i - 1] == ' ')
        {
            if (answer[i] >= 'a' && answer[i] <= 'z')
            {
                answer[i] -= 32;
            }
            continue;
        }
        else if (i != 0 && answer[i - 1] != ' ')
        {
            if (answer[i] >= 'A' && answer[i] <= 'Z')
            {
                answer[i] += 32;
            }
            continue;
        }

        if (i == 0)
        {
            if (answer[0] >= 'a' && answer[0] <= 'z')
            {
                answer[0] -= 32;
            }
        }

    }
    return answer;
}

void main()
{
    cout << solution("3people unFollowed me") << endl;
}

/* �����ڵ� 1*/

#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";

    answer += toupper(s[0]);
    for (int i = 1; i < s.size(); i++)
        s[i - 1] == ' ' ? answer += toupper(s[i]) : answer += tolower(s[i]);

    return answer;
}

//int tolower(int c) : ���ڷ� �ְ� �Ǹ� �ƽ�Ű�ڵ�ǥ�� ����� 10������ ��ȯ�ȴ�.
// 'A'�� ������ 65�� �ް� �ȴ�. 
// �Ű������� �빮�� �� ��� �ҹ��ڷ� ��ȯ (�빮�ڰ� �ƴϸ� �״�� ��ȯ)

//int toupper(int c) : ���� �ݴ�� �ҹ��ڸ� �빮�ڷ� ��ȯ


/* �����ڵ� 2*/

#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer = s;
    answer.at(0) = toupper(answer.at(0));

    for (int i = 1; i < answer.size(); i++) {
        if (answer[i - 1] == ' ')
            answer[i] = toupper(answer[i]);
        else
            answer[i] = tolower(answer[i]);
    }
    return answer;
}