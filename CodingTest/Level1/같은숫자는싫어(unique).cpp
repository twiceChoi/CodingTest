#include <vector>
#include <iostream>

using namespace std;


/* ���ڵ� */
vector<int> solution(vector<int> arr)
{
    vector<int> answer(1, arr[0]);

    for (int i = 1; i < arr.size(); ++i)
    {
        if (arr[i] == arr[i-1])
            continue;

        answer.push_back(arr[i]);
    }

    return answer;
}

void main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(3);
    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(1);

    cout << solution(arr)[0] << endl;
    cout << solution(arr)[1] << endl;
    cout << solution(arr)[2] << endl;
    cout << solution(arr)[3] << endl;
}

/* �����ڵ� */
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr)
{

    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    vector<int> answer = arr;
    return answer;
}

//unique : vector �迭���� �ߺ����� �ʴ� ���ҵ��� �տ������� ä�������� �Լ�
//algorithm ���

//erase �Լ��� �̿�
//v.erase(v.begin()+s, v.begin()+e) ��ɾ �Է��ϸ� [s,e) ���Ұ� ����
//v.erase(unique(v.begin(), v.end()), v.end());