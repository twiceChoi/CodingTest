#include <string>
#include <vector>

using namespace std;
/* ���� Ǯ��*/
string solution(int n) {
    string answer = "";
    string answer1 = "��";
    string answer2 = "��";
    bool arr[n];
    for (int i = 0; i < n; ++i)
    {
        if (i % 2)
            arr[i] = true;
        else
            arr[i] = false;


        if (arr[i])
        {
            answer += answer2;
        }
        else
        {
            answer += answer1;
        }
    }



    return answer;
}

/* ����Ǯ�� */
#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";

    for (int i = 0; i < n; i++)
        i & 1 ? answer += "��" : answer += "��";

    return answer;
}