#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/* ���� § �ڵ� */

/* sort�� ���� 2���޴� ������ */
bool StringSort(string string1, string string2)
{
    if (stoll(string1) > stoll(string2))
        return false;/* false �ϰ�� change */
    else
        return true; /* true �ϰ�� �ȹٲ۴� */
}

string solution(string s) {
    string answer = "";
    vector<string>vNum;
  
    for (int i = 0; i < s.size(); ++i)
    {
        string answer = "";
        while (true)
        {
            answer += s[i];
            ++i;
            if (i == s.size() || s[i] == ' ') /* �ǳ��� ����ؼ� ¥�� */
            {
                vNum.push_back(answer);
                break;
            }
            
        }
    }
    sort(vNum.begin(), vNum.end(), StringSort);

    answer += *vNum.begin();
    answer += ' ';
    answer += *(vNum.end() - 1);
    
    return answer;
}

void main()
{
    string s = "11 22 33 -4";
    cout << solution(s) << endl;
}