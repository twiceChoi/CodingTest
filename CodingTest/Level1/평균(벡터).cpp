#include <string>
#include <vector>

using namespace std;

/* �� ��� */
double solution(vector<int> arr) {
    double answer = 0;

    for (auto& elem : arr)
    {
        answer += elem;
    }

    answer /= arr.size();

    return answer;
}

//arr.sizeof() -> ������ ����
//sizeof(arr) -> 24

int main()
{

}