#include <string>
#include <vector>

using namespace std;

/* 내 답안 */
double solution(vector<int> arr) {
    double answer = 0;

    for (auto& elem : arr)
    {
        answer += elem;
    }

    answer /= arr.size();

    return answer;
}

//arr.sizeof() -> 원소의 개수
//sizeof(arr) -> 24

int main()
{

}