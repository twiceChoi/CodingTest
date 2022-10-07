#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";

    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == ' ')
            continue;


        if (s[i] <= 'Z')
        {
            s[i] += n;
            if (s[i] > 'Z')
            {
                s[i] = (s[i] - 'Z') % ('Z' - 'A') + 'A' - 1;
            }
        }
        else if (s[i] >= 'a')
        {
            //s[i] += n; 
           //여기서 아스키 코드가 char형 128까지라서 넘어가기 떄문에 안된다.
            //항상 자료형을 생각하자.
            if (s[i] + n > 'z')
            {
                s[i] = (s[i] - 'z') % ('z' - 'a') + 'a' - 1 + n;
            }
            else
            {
                s[i] += n;
            }
        }

    }

    return s;
}