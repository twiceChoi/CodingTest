#include <string>
#include <vector>
#include <algorithm>
using namespace std;


/* ���� Ǯ�� */
int solution(vector<int> numbers) {
    int answer = 0;
   
    for (int i = 0; i < 10; ++i)
    {
        auto iter = find(numbers.begin(), numbers.end(), i);
        if (iter == numbers.end())
            answer += i;
    }

    return answer;
}

/* ���� Ǯ�� : ���տ��� ����*/
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {

    int answer = 45;

    for (int i = 0; i < numbers.size(); i++)
        answer -= numbers[i];

    return answer;
}

