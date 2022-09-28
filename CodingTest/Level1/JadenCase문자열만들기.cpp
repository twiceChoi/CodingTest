#include <string>
#include <vector>
#include <iostream>

using namespace std;
/* 내코드 */
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

/* 참고코드 1*/

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

//int tolower(int c) : 문자로 넣게 되면 아스키코드표에 기반한 10진수로 변환된다.
// 'A'가 들어오면 65로 받게 된다. 
// 매개변수가 대문자 일 경우 소문자로 반환 (대문자가 아니면 그대로 반환)

//int toupper(int c) : 위와 반대로 소문자만 대문자로 반환


/* 참고코드 2*/

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