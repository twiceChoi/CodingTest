#include <string>
#include <vector>

using namespace std;

/* ���� Ǯ�� */
int solution(int num) {
    int answer = 0;
    long n = num; /* ��� ���� INT �ڷ����� �Ѿ�� �����̴�.*/
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

/* ���� Ǯ�� */
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