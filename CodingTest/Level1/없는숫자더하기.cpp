#include <string>
#include <vector>
#include <algorithm>
using namespace std;


/* 나의 풀이 */
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

/* 참고 풀이 : 총합에서 뺴기*/
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {

    int answer = 45;

    for (int i = 0; i < numbers.size(); i++)
        answer -= numbers[i];

    return answer;
}

