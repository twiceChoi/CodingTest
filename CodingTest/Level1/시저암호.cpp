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
           //���⼭ �ƽ�Ű �ڵ尡 char�� 128������ �Ѿ�� ������ �ȵȴ�.
            //�׻� �ڷ����� ��������.
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