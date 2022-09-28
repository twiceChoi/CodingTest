//3진법

#include <string>
#include <vector>
#include <cmath>
using namespace std;

/* 내코드 */
int solution(int n) {
    vector<int> answer;
    int iPow = 0;
    int answer10 = 0;
    while (true)
    {
        if (n < 3)
        {
            answer.push_back(n);
            break;
        }
        answer.push_back(n % 3);
        ++iPow;
        n /= 3;
    }

    for (int i = 0; i <= iPow; ++i)
    {
        answer10 += pow(3, i) * answer[iPow - i];
    }

    return answer10;
}
/* 참고코드 */

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> v;
    while (n > 0) {
        v.push_back(n % 3);
        n /= 3;
    }
    int k = 1;
    while (!v.empty()) {
        answer += k * v.back();
        v.pop_back();
        k *= 3;
    }

    return answer;
}