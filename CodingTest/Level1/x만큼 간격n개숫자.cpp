#include <string>
#include <vector>

using namespace std;

/* ��Ǯ�� */
vector<long long> solution(int x, int n) {
    vector<long long> answer;

    for (int i = 0; i < n; ++i)
    {
        answer.push_back(x * (i + 1));
    }
    return answer;
}


/* ���� Ǯ�� */
#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer(n, x);

    for (int i = 1; i < n; i++)
        answer[i] = answer[i - 1] + x;

    return answer;
}

//vector<int>v; ����ִ� v�� ����
//vector<int> v(5); 0���� �ʱ�ȭ�� ���� 5�� ����
//vector<int> v(5, 2) 2�� �ʱ�ȭ�� ���� 5���� ������ vector v�� ����
