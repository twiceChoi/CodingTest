#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

/* ���� Ǯ�� */
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> qanswer;
    int j = 0;
    int iX = 0;
    for (int i = 0; i < progresses.size(); ++i)
    {
        while (progresses[i] + speeds[i] * j < 100) /* 100���� ū ��� */
        {
            ++j;
        }
        progresses[i] += speeds[i] * j;
        qanswer.emplace(j); /* ť�� ���� �Ⱓ�� �־��ش�.*/
    }
    iX = qanswer.front();
    int k = 0;
    while (true)
    {
        if (iX != qanswer.front()) /* �տ��� ����Ⱓ�� �ϳ��� ���� : �ٸ� ��쿡�� ���� ���信 push */
        {
            iX = qanswer.front();
            answer.emplace_back(k);
            k = 0;
        }

        ++k;
        qanswer.pop();

        if (qanswer.empty())
        {
            answer.emplace_back(k); 
            break;
        }
    }
    return answer;
}
void main() {

    vector<int> progresses;
    progresses.push_back(93);
    progresses.push_back(30);
    progresses.push_back(55);


    vector<int> speeds;
    speeds.push_back(1);
    speeds.push_back(30);
    speeds.push_back(5);


    cout << solution(progresses, speeds)[0] << endl;
    cout << solution(progresses, speeds)[1] << endl;
}

/*  Queue ���� �ڵ�  */
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    queue<int> q;

    for (int i = 0; i < progresses.size(); ++i)
    {
    }

}