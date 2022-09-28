#include <string>
#include <vector>
#include <iostream>

using namespace std;
/* 재귀함수로 접근*/
void Rec(string s, vector<int>* answer)
{
    vector<string> anserstring;
    int NumCount = 0;
    string          string1;

    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '0')
            (*answer)[1] += 1; /* 여기서 포인터 연산자 위치 헷갈렸음 */

        else
            ++NumCount;
    }

    while (true)
    {
        if (NumCount == 1) /* 이게 위로 올라와야 한다. */
        {
            anserstring.push_back("1"); /* string 일때는  "" 이고 string의 원소를 가리킬땐 '' 이다.*/
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
    return; /* return.을 해줘야 한다. */
}



vector<int> solution(string s) {

    vector<int> answer(2, 0);

    /* 포인터로 최종 개수 올림 */
    Rec(s, &answer);

    return answer;
}

void main()
{
    cout << solution("110010101001")[0] << endl;
    cout << solution("110010101001")[1] << endl;
}


/* 참고코드 */
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(string s) {
    int zeros{ 0 }, num_transform{ 0 }; vector<bool> bin; /* 변환 값들 */
    for_each(s.cbegin(), s.cend(), [&bin](const char c) {bin.emplace_back(c == '1'); });  //s를 이진수로 변환
    while (true) {
        if (bin == vector<bool>{true}) break;
        int ones = count(bin.cbegin(), bin.cend(), true);    //1갯수를 셈
        zeros += bin.size() - ones;                          //0갯수를 셈
        bin.clear();
        while (ones > 0) { bin.emplace_back(ones % 2); ones /= 2; }//1갯수를 2진수로 바꿈. 순서는 거꾸로지만 계산에는 영향없음
        ++num_transform;                                   //이진변환 횟수 기록
    }
    return { num_transform,zeros };
}

//람다식 복습
[<captures>](<parameters>) < specifiers > -> <retrun_type>
{
    // body
}

캡처의 종류
[] : 비어 있으므로, 캡처하지 않습니다.

= : 값에 의한 캡처, 모든 외부 변수를 캡처합니다.람다 식 안에서 수정할 수는 없습니다.

& : 참조에 의한 캡처입니다.모든 외부 변수를 캡처합니다.

<변수 이름> : 특정 변수를 값으로 캡처합니다.람다 식 안에서 수정할 수 없습니다.

& <변수 이름> : 특정 변수를 참조로 캡처합니다.

//여러 캡쳐를 섞어서 사용가능
//인라인화 한다는데 인라인 함수에 대해 다시 한번 개념정리 하기 
