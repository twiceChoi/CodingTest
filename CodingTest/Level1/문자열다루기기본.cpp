#include <string>
#include <vector>

using namespace std;

/* 내코드 */
bool solution(string s) {
    bool answer = true;

    if (s.size() == 4 || s.size() == 6)
    {
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] < '0' || s[i] > '9')
                return false;

        }
        return true;
    }
    return false;
}

/* 참고 코드 */

#include <string>
#include <vector>
using namespace std;

bool solution(string s) {
    bool answer = true;

    for (int i = 0; i < s.size(); i++)
    {
        if (!isdigit(s[i]))
            answer = false;
    }

    return s.size() == 4 || s.size() == 6 ? answer : false;
}

//isdigit : 