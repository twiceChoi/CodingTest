#include <string>
#include <vector>
#include <cmath>

using namespace std;

/* 나의 풀이 */
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

/* 참고 풀이 */

#include <string>

using namespace std;

string solution(string s) {
    return s.length() & 1 ? s.substr(s.length() * 0.5, 1) : s.substr(s.length() * 0.5 - 1, 2);
}

//substr() : string의 부분 문자열을 추출하는 함수이다. 시작지점과 길이를 넣으면 된다.