#include <string>
#include <vector>

using namespace std;
/* 내 풀이 */
long long solution(int a, int b) {
    long long answer = 0;


    if (a > b)
    {
        for (int i = b; i <= a; ++i)
        {
            answer += i;
        }
    }
    else if (a == b)
    {
        return a;
    }
    else
    {
        for (int i = a; i <= b; ++i)
        {
            answer += i;
        }
    }
    return answer;
}


/* 참고풀이 : 비트연산 */
#include <string>
#include <vector>
using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    if (a > b) a ^= b ^= a ^= b;
    answer = (long long)b * -~b / 2 - (long long)a * ~- a / 2;
    return answer;
}


/* 시그마 공식 */
using namespace std;

long long solution(int a, int b) {
    return (long long)(a + b) * (abs(a - b) + 1) / 2;
}