#include <string>
#include <vector>

using namespace std;

/* 나의 풀이 */
int solution(int num) {
    int answer = 0;
    long n = num; /* 계산 도중 INT 자료형을 넘어가기 떄문이다.*/
    while (n != 1)
    {
        if (n % 2)
            n = n * 3 + 1;
        else
            n /= 2;

        ++answer;

        if (answer >= 500)
            return -1;
    }

    return answer;
}

/* 참고 풀이 */
#include<iostream>
using namespace std;

int collatz(int num)
{
    int answer = 0;
    cout << num << "\n";
    while (answer++ <= 500) {
        num = num % 2 == 0 ? num / 2 : num * 3 + 1;
        if (num == 1) break;
    }

    return answer > 500 ? -1 : answer;
}