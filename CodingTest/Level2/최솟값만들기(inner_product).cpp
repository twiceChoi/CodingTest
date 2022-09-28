#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

/* 내풀이 : 작은 순으로 큰순으로 반대로 나열해서 곱하면 된다.*/
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

/* 참고 풀이 */
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
int solution(vector<int> A, vector<int> B) {
    sort(A.begin(), A.end());  sort(B.rbegin(), B.rend());
    return inner_product(A.begin(), A.end(), B.begin(), 0);
}

//rbegin()과 rend()는 역방향 반복자 이다. 


/* 범용수치 알고리즘: <numeric>헤더파일을 포함해야 한다.  */
//accumulate :지정한 구간에 속한 값들을 모든 더한 값을 계산한다.


//vec1에 있는 값들을 더한다.
int result1 = accumulate(vec1.begin(), vec1.end(), 0);

//vec1에 있는 값들을 더하고  10을 더한다.
int result1 = accumulate(vec1.begin(), vec1.end(), 10);

//inner_product : 입력 시퀀스의 내적을 계산하는 알고리즘으로 기본적으로는 +와 *을 사용한다. 
