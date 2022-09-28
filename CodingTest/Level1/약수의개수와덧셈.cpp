#include <string>
#include <vector>
#include <iostream>

using namespace std;

/* ��Ǯ�� */
int solution(int left, int right) {
    int answer = 0;
   
    for (int i = left; i <= right; ++i)
    {
        if (i == 1)
        {
            answer -= 1;
            continue;
        }
        if (i == 2)
        {
            answer += 2;
            continue;
        }
        int iNum = 0;
        int j;
        for (j = 1; j * j < i; ++j)
        {
            if (!(i % j))
                ++iNum;

        }


        if (!(i % (j * j))) /* ���⼭ j-1�� �߰�, 3�� �����Ҷ� ������ ���� */
            answer -= i;
        else
            answer += i;

    }
    return answer;
}

void main()
{
    cout << solution(1,3) << endl;
}

/* ���� �ڵ� */

/* for�� ���� �ΰ� */
/* ����Լ� */
int sign(int n, int count = 1) {
    for (int i = 1, last = n >> 1; i <= last; ++i) if (n % i == 0) ++count;
    return count & 1 ? -1 : 1;
}
int solution(int a, int b) { 
    return a > b ? 0 : sign(a) * a + solution(a + 1, b); 
}