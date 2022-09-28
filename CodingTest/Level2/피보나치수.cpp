#include <string>
#include <vector>
#include <iostream>
using namespace std;

/* 내가 짠 코드 : 재귀함수 형식 */
void F(int iNum, int* iAnswer)
{
    if (iNum == 1)
    {
        ++(*iAnswer);
        return;
    }
    else if (iNum == 0)
    {
        return;
    }

    F(iNum - 2, iAnswer);
    F(iNum - 1, iAnswer);
}

int solution(int n) {
    int answer = 0;

    F(n, &answer);

    return answer;
}

void main()
{
    cout << solution(3) << endl;
}

//특정 조건을 만족하지 못할 때까지(while, repeat-while) 또는 더 이상 확인할 요소가 없을 때까지(for-in)
//블락 내부를 반복적으로 수행하고 반복문을 빠져 나온다.
//
//Memoization.피보나치 수열을 통해 반복문, 재귀함수와 비교하기
//
//ex.피보나치 수열
//
//    : 재귀함수의 시간복잡도가 더 나쁘다.
//
//    (이유 : 재귀함수는 다른 함수 호출 할 때마다 2 갈래로 나뉨O(2 ^ N).
//        반면, 반복문은 기존값에 누적해서 반복적으로 더하기 때문에 O(N))




/* 반복문으로 해야지 더 빠르다 .*/

/* 새로 푼 식 */
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;

    int arr[n + 1];
    arr[0] = 0;
    arr[1] = 1;

    for (int i = 2; i <= n; ++i)
    {
        arr[i] = arr[i - 2] % 1234567 + arr[i - 1] % 1234567;
    }

    return arr[n] % 1234567;
}


/* 참고 코드 : 복잡도를 줄여주는 코드 매트릭스로 */

#include<iostream>
#include<vector>
using namespace std;

typedef vector<vector<long long>> matrix;

matrix operator* (matrix& a, matrix& b) {
    int n = a.size();
    matrix c(n, vector<long long>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                c[i][j] += a[i][k] * b[k][j];
    return c;
}

long long fibonacci(int n)
{
    matrix res = { {1, 0},{0, 1} };
    matrix fib = { {1, 1},{1, 0} };
    while (n) {
        if (n % 2 == 1) res = res * fib;
        fib = fib * fib;
        n *= 0.5;
    }
    return res[0][1];
}

int main()
{
    int testCase = 10;
    long long testAnswer = fibonacci(testCase);

    cout << testAnswer;
}