#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/* 내풀이 */
vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;

    for (int i = 0; i < arr.size(); ++i)
    {
        if (arr[i] % divisor == 0)
            answer.push_back(arr[i]);
    }
    if (answer.size() == 0)
        answer.push_back(-1);

    sort(answer.begin(), answer.end());
    return answer;
}

/* 참고 풀이 */
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] % divisor == 0)
            answer.push_back(arr[i]);
    }

    return answer.empty() ? vector<int>(1, -1) : answer;
}