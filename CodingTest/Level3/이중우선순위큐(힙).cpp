#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <unordered_set>
#include <sstream> // ���ڿ� �����ֱ� ����

using namespace std;

#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer(2);
    priority_queue<int, vector<int>, greater<int>> pq_asc;
    priority_queue<int, vector<int>> pq_des;
    int cnt = 0;

    for (string op : operations) {
        // ť�� ������� �� �ʱ�ȭ
        if (!cnt) {
            while (!pq_asc.empty()) pq_asc.pop();
            while (!pq_des.empty()) pq_des.pop();
        }

        // ����
        if (op[0] == 'I') {
            pq_des.push(stoi(op.substr(2)));
            pq_asc.push(stoi(op.substr(2)));
            cnt++;
        }
        // ����
        else {
            // �� ť�� �����͸� �����϶�� ������ ��� ����
            if (!cnt) continue;

            // �ִ� ����
            if (op[2] == '1') {
                pq_des.pop();
                cnt--;
            }
            // �ּڰ� ����
            else {
                pq_asc.pop();
                cnt--;
            }
        }

    }

    if (cnt) {
        answer[0] = pq_des.top();
        answer[1] = pq_asc.top();
    }

    return answer;
}

void main()
{
    vector<string> operations;
    operations.push_back("I 16");
    operations.push_back("I -5643");
    operations.push_back("D -1");
    operations.push_back("D 1");
    operations.push_back("D 1");
    operations.push_back("I 123");
    operations.push_back("D -1");
    cout << solution(operations)[0] << endl;
    cout << solution(operations)[1] << endl;
}

