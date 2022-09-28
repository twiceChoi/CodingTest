#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n) {
    int answer = 0;

    for (int i = 1; i <= (n); ++i)
    {
        for (int j = i; j <= (n); ++j)
        {
            //i에서 j까지 더한 결과
            int iSum = (i + j) * (j - i + 1) / 2;

            if (iSum > n)
                break;

            if (iSum == n)
            {
                ++answer;
                if (j - i == 1)
                    return ++answer;

                break;
            }

        }
    }

    return answer;
}