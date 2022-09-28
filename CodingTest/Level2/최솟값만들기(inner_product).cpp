#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

/* ��Ǯ�� : ���� ������ ū������ �ݴ�� �����ؼ� ���ϸ� �ȴ�.*/
int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<int>());

    for (int i = 0; i < A.size(); ++i)
    {
        answer += A[i] * B[i];
    }

    return answer;
}

void main()
{
    vector<int> A;
    A.push_back(1);
    A.push_back(2);
    A.push_back(4);

    vector<int> B;
    B.push_back(5);
    B.push_back(4);
    B.push_back(4);
    cout << solution(A,B) << endl;
}

/* ���� Ǯ�� */
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
int solution(vector<int> A, vector<int> B) {
    sort(A.begin(), A.end());  sort(B.rbegin(), B.rend());
    return inner_product(A.begin(), A.end(), B.begin(), 0);
}

//rbegin()�� rend()�� ������ �ݺ��� �̴�. 


/* �����ġ �˰���: <numeric>��������� �����ؾ� �Ѵ�.  */
//accumulate :������ ������ ���� ������ ��� ���� ���� ����Ѵ�.


//vec1�� �ִ� ������ ���Ѵ�.
int result1 = accumulate(vec1.begin(), vec1.end(), 0);

//vec1�� �ִ� ������ ���ϰ�  10�� ���Ѵ�.
int result1 = accumulate(vec1.begin(), vec1.end(), 10);

//inner_product : �Է� �������� ������ ����ϴ� �˰������� �⺻�����δ� +�� *�� ����Ѵ�. 
