#include <string>
#include <vector>
#include <iostream>

using namespace std;

/* 내풀이 */
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


        if (!(i % (j * j))) /* 여기서 j-1을 했고, 3을 연산할때 문제가 생김 */
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

/* 참고 코드 */

/* for에 조건 두개 */
/* 재귀함수 */
int sign(int n, int count = 1) {
    for (int i = 1, last = n >> 1; i <= last; ++i) if (n % i == 0) ++count;
    return count & 1 ? -1 : 1;
}
int solution(int a, int b) { 
    return a > b ? 0 : sign(a) * a + solution(a + 1, b); 
}