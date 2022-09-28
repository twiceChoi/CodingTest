#include <string>
#include <vector>
#include <iostream>

using namespace std;
/* ����Լ��� ����*/
void Rec(string s, vector<int>* answer)
{
    vector<string> anserstring;
    int NumCount = 0;
    string          string1;

    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '0')
            (*answer)[1] += 1; /* ���⼭ ������ ������ ��ġ �򰥷��� */

        else
            ++NumCount;
    }

    while (true)
    {
        if (NumCount == 1) /* �̰� ���� �ö�;� �Ѵ�. */
        {
            anserstring.push_back("1"); /* string �϶���  "" �̰� string�� ���Ҹ� ����ų�� '' �̴�.*/
            break;
        }
        anserstring.push_back(to_string(NumCount % 2));
        NumCount /= 2;
    }

    for (int i = anserstring.size() - 1; i >= 0; --i)
    {
        string1 += anserstring[i];
    }


    (*answer)[0] += 1;
 
    if (string1 == "1")
    {
        return;
    }
    Rec(string1, answer);
    return; /* return.�� ����� �Ѵ�. */
}



vector<int> solution(string s) {

    vector<int> answer(2, 0);

    /* �����ͷ� ���� ���� �ø� */
    Rec(s, &answer);

    return answer;
}

void main()
{
    cout << solution("110010101001")[0] << endl;
    cout << solution("110010101001")[1] << endl;
}


/* �����ڵ� */
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(string s) {
    int zeros{ 0 }, num_transform{ 0 }; vector<bool> bin; /* ��ȯ ���� */
    for_each(s.cbegin(), s.cend(), [&bin](const char c) {bin.emplace_back(c == '1'); });  //s�� �������� ��ȯ
    while (true) {
        if (bin == vector<bool>{true}) break;
        int ones = count(bin.cbegin(), bin.cend(), true);    //1������ ��
        zeros += bin.size() - ones;                          //0������ ��
        bin.clear();
        while (ones > 0) { bin.emplace_back(ones % 2); ones /= 2; }//1������ 2������ �ٲ�. ������ �Ųٷ����� ��꿡�� �������
        ++num_transform;                                   //������ȯ Ƚ�� ���
    }
    return { num_transform,zeros };
}

//���ٽ� ����
[<captures>](<parameters>) < specifiers > -> <retrun_type>
{
    // body
}

ĸó�� ����
[] : ��� �����Ƿ�, ĸó���� �ʽ��ϴ�.

= : ���� ���� ĸó, ��� �ܺ� ������ ĸó�մϴ�.���� �� �ȿ��� ������ ���� �����ϴ�.

& : ������ ���� ĸó�Դϴ�.��� �ܺ� ������ ĸó�մϴ�.

<���� �̸�> : Ư�� ������ ������ ĸó�մϴ�.���� �� �ȿ��� ������ �� �����ϴ�.

& <���� �̸�> : Ư�� ������ ������ ĸó�մϴ�.

//���� ĸ�ĸ� ��� ��밡��
//�ζ���ȭ �Ѵٴµ� �ζ��� �Լ��� ���� �ٽ� �ѹ� �������� �ϱ� 
