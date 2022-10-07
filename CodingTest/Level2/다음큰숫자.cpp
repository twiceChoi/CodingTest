#include <string>
#include <vector>
#include <iostream>
using namespace std;

/* 내가 푼 방법 */
int solution(int n) {
    int answer = n + 1;
    int answerTemp = n + 1;

    //1의 개수 
    int iNumOne = 0;
    while (n > 0)
    {
        if (n % 2 == 1)
            ++iNumOne;

        n /= 2;
    }

    int iNumTempOne = 0;
    while (true)
    {
        if (answer == 0)
        {
            if (iNumTempOne == iNumOne)
                return answerTemp;

            ++answerTemp;
            answer = answerTemp;
            iNumTempOne = 0;
        }

        if (answer % 2 == 1)
            ++iNumTempOne;

        answer /= 2;

    }

    return answerTemp;
}

void main()
{
    cout << solution(78) << endl;
}
//이런경우 비트 연산을 통해 확인하면 될거같다.

/* 참고 풀이 */
#include <bitset>

using namespace std;

int solution(int n) {
    int num = bitset<20>(n).count();

    while (bitset<20>(++n).count() != num);
    return n;
}


/* 참고 풀이 2*/
#include<iostream>
using namespace std;

int getCntNum1(int n)
{
    int nCnt = 0;
    for (int i = 0; i < 31; i++)
    {
        if (n & 0x01 << i)
            nCnt++;
    }
    return nCnt;
}

int nextBigNumber(int n)
{
    int nNum1Cnt = getCntNum1(n);

    while (1)
    {
        n++;
        if (nNum1Cnt == getCntNum1(n))
            return n;
    }
}

int main()
{
    int n = 832656;

    //아래는 테스트 출력을 위한 코드입니다.
    cout << nextBigNumber(n);
}