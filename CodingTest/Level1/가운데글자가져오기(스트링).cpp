#include <string>
#include <vector>
#include <cmath>

using namespace std;

/* ���� Ǯ�� */
string solution(string s) {
    string answer = "";

    if (s.size() & 1)
        answer += s[floor(s.size() / 2)];
    else
    {
        answer += s[s.size() / 2 - 1];
        answer += s[s.size() / 2];
    }

    //s.size() & 1 ? answer += s[floor(s.size() / 2)] : answer = s[s.size() / 2 - 1] + s[s.size() / 2 ];
    return answer;
}

/* ���� Ǯ�� */

#include <string>

using namespace std;

string solution(string s) {
    return s.length() & 1 ? s.substr(s.length() * 0.5, 1) : s.substr(s.length() * 0.5 - 1, 2);
}

//substr() : string�� �κ� ���ڿ��� �����ϴ� �Լ��̴�. ���������� ���̸� ������ �ȴ�.