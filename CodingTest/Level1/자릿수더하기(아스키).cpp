#include <iostream>

/* 나의 풀이 */
using namespace std;
int solution(int n)
{
    int answer = 0;

    while (true)
    {
        answer += n % 10;
        n = n / 10;

        if (n < 1)
            break;
    }

    return answer;
}


/* 참고 풀이 */
#include <iostream>
#include <string>

using namespace std;
int solution(int n)
{
    int answer = 0;

    string s = to_string(n);

    //s.size() 는 문자열 길이 
    for (int i = 0; i < s.size(); i++) 
        answer += (s[i] - '0');


    return answer;
}

//to_string(숫자) 숫자를 스트링 타입으로 

//string 의 경우 length() 랑 size() 가 같다. 
//string 또한 배열처럼 인덱스로 접근이 가능하다. 
//인덱스로 접근하여 바꿔치기도 가능


/* 아스키 코드를 이용하여 char형을 int 형으로 변환 */
//해당 문자의 ascii 코드 값이 정수로 저장되어있다.
//48 번부터 숫자 0 ~ 9를 할당하고 있다.



//문자로 부터 순수한 숫자를 얻는 방법 

char c = '1';
int n = c - 48;

//n은 순수한 숫자 1을 얻을 수 있다. 

char c = '1';
int n = c - '0';
