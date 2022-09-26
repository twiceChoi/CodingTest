#include <string>
#include <vector>

using namespace std;

/* 내풀이 */
vector<long long> solution(int x, int n) {
    vector<long long> answer;

    for (int i = 0; i < n; ++i)
    {
        answer.push_back(x * (i + 1));
    }
    return answer;
}


/* 참고 풀이 */
#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer(n, x);

    for (int i = 1; i < n; i++)
        answer[i] = answer[i - 1] + x;

    return answer;
}

//vector<int>v; 비어있는 v를 생산
//vector<int> v(5); 0으로 초기화된 원소 5개 생성
//vector<int> v(5, 2) 2로 초기화된 원소 5개를 가지는 vector v를 생산
