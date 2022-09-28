#include <string>
#include <vector>
#include <iostream>
using namespace std;

/* ���� § �ڵ� : ����Լ� ���� */
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

//Ư�� ������ �������� ���� ������(while, repeat-while) �Ǵ� �� �̻� Ȯ���� ��Ұ� ���� ������(for-in)
//��� ���θ� �ݺ������� �����ϰ� �ݺ����� ���� ���´�.
//
//Memoization.�Ǻ���ġ ������ ���� �ݺ���, ����Լ��� ���ϱ�
//
//ex.�Ǻ���ġ ����
//
//    : ����Լ��� �ð����⵵�� �� ���ڴ�.
//
//    (���� : ����Լ��� �ٸ� �Լ� ȣ�� �� ������ 2 ������ ����O(2 ^ N).
//        �ݸ�, �ݺ����� �������� �����ؼ� �ݺ������� ���ϱ� ������ O(N))




/* �ݺ������� �ؾ��� �� ������ .*/

/* ���� Ǭ �� */
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


/* ���� �ڵ� : ���⵵�� �ٿ��ִ� �ڵ� ��Ʈ������ */

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