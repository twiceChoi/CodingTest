#include <string>
#include <vector>

using namespace std;
/* ���� ���� */
string solution(string s) {
    string answer = s;

    int iCount = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (iCount % 2 == 0)
        {
            answer[i] = toupper(answer[i]);
        }
        else if (iCount % 2 == 1)
        {
            answer[i] = tolower(answer[i]);
        }

        if (answer[i] != ' ')
            ++iCount;
        else
            iCount = 0;
    }

    return answer;
}

/* ���� Ǯ�� : upper lower ���� ���� */
char toUp(char word) {
    if (word >= 'a' && word <= 'z') {
        word = word - ('a' - 'A');
    }
    return word;
}

char toLow(char word) {
    if (word >= 'A' && word <= 'Z') {
        word = word + ('a' - 'A');
    }
    return word;
}