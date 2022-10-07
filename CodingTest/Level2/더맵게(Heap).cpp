#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
/* ���� Ǭ �켱���� ť */
int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> foods = { scoville.begin(), scoville.end() };
    /* Greater �� �ȽἭ �Ǽ� �ѹ� */
    while (true)
    {
        if (foods.top() >= K)
        {
            break;
        }
        if (foods.size() < 2)
            return -1;

        int iMin1 = 0;
        int iMin2 = 0;
        iMin1 = foods.top();
        foods.pop();
        iMin2 = foods.top();
        foods.pop();
        foods.emplace(iMin1 + iMin2 * 2);
        ++answer;
    }

    return answer;
}

void main()
{
    vector<int> scoville = { 1, 2, 3, 9, 10, 12 };
    int K = 7;
    cout << solution(scoville, K) << endl;
}

/* ���� �ڵ� : �ּ������� ���� */

//�ּ� heap ����
make_heap(scoville.begin(), scoville.end(), greater<int>());

while (front < K)
{
    pop_heap(scoville.begin(), scoville.end());
    temp = scoville.back();
    scoville.pop_back();

    //heap ������        
    sort_heap(scoville.begin(), scoville.end());
    ++count;

    if (count == 1)
    {
        temp2 += temp;
        temp = 0;
    }

    if (count == 2)
    {
        ++answer;
        temp2 = temp2 + (temp * 2);

        //�� ���� ���� ���Ѱ��� heap�� ����
        scoville.push_back(temp2);
        push_heap(scoville.begin(), scoville.end());

        //���� �ٽ� ����
        sort_heap(scoville.begin(), scoville.end());

        temp = 0;
        temp2 = 0;
        count = 0;

        if (scoville.size() == 1 && scoville.front() < K)
        {
            answer = -1;
            break;
        }

        front = scoville.front();
    }
}

return answer;