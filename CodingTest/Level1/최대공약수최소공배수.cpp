#include <string>
#include <vector>
#include <iostream>

using namespace std;
/* �� Ǯ�� */
vector<int> solution(int n, int m) {
    vector<int> answer(2,1);

    if(n > m )
        n ^= m ^= n ^= m;
   
    for (int i = 2; i < n + 1; ++i) /* �Ųٷ� �ϸ� while�� �Ƚᵵ �ȴ�. �װ� �ּ� ������� �ȴ� ���� ũ�� ������ */
    {
        while(n % i == 0 && m % i == 0) 
        {
            n /= i;
            m /= i;
            answer[0] *= i;
        }
    }
    answer[1] = answer[0] * n * m;
    return answer;
}

void main()
{
    cout << solution(12, 8)[0] << endl;
    cout << solution(12, 8)[1] << endl;
}







/* ���� �ڵ� */
#include<vector>
#include<iostream>
using namespace std;


int Euclidean(int a, int b)
{
    return b ? Euclidean(b, a % b) : a;
}

vector<int> gcdlcm(int a, int b)
{
    vector<int> answer;
    // ��Ŭ���� ȣ���� : �ִ������� ���ϴ� �˰����̴�.

    answer.push_back(Euclidean(a, b));

    answer.push_back(a * b / answer[0]);

    return answer;
}

int main()
{
    int a = 3, b = 12;
    vector<int> testAnswer = gcdlcm(a, b);

    cout << testAnswer[0] << " " << testAnswer[1];
}