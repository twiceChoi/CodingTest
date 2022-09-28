#include<string>
#include <iostream>

using namespace std;
/* 나의 풀이 */
bool solution(string s)
{
    int i = 0;
    int iCount = 1;
    for (i = 0; i < s.size(); ++i)
    {
        if (s[0] != '(')
            return false;
        else if(i != 0 && s[i] == '(')
            ++iCount;
        else if (i != 0 && s[i] == ')')
            --iCount;

        if (iCount < 0)
            return false;
    }

    if (iCount != 0)
        return false;

    return true;
}

void main()
{
    cout << solution("(())()") << endl;
}


/* 참고 코딩 */
#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    int n = 0;
    for (int i = 0; i < s.length(); i++) {
        if (n < 0)
            return false;
        if (s[i] == '(')
            n++;
        else if (s[i] == ')')
            n--;
    }
    return n == 0;
}