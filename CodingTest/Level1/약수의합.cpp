#include<iostream>
#include <string>
#include <vector>

using namespace std;

/* 나의 풀이 */
int solution(int n) {
    int answer = 0;

    answer += n;

    if (n == 1)
        return answer;

    for (int i = 1; i < n / 2.f + 1; ++i)
    {
        if ((n % i) == 0)
        {
            answer += i;
        }
    }

    return answer;
}

/* 참고 풀이 */

#include<iostream>
#include<cmath>
using namespace std;

int sumDivisor(int n)
{
    int sum = 0;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        { 
            sum += i; 

            if (n != i * i) 
                sum += n / i; 
        }
    }
    return sum;
}

//sqrt(n) : 제곱근 결과를 return.


int main()
{
    int testCase = 12;
    int testAnswer = sumDivisor(testCase);

    cout << testAnswer;
}