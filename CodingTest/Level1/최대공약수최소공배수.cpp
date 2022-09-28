#include <string>
#include <vector>
#include <iostream>

using namespace std;
/* 내 풀이 */
vector<int> solution(int n, int m) {
    vector<int> answer(2,1);

    if(n > m )
        n ^= m ^= n ^= m;
   
    for (int i = 2; i < n + 1; ++i) /* 거꾸로 하면 while문 안써도 된다. 그게 최소 공약수가 된다 가장 크기 떄문에 */
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







/* 참고 코드 */
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
    // 유클리드 호제법 : 최대공약수를 구하는 알고리즘이다.

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