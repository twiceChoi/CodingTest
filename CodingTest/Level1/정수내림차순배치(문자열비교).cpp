#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
/* 내가 구현 */
long long solution(long long n) {
    long long answer = 0;
    string s = to_string(n);
    int iSize = s.size();
    vector<int>vNum;
    for (int i = 0; i < iSize; ++i)
    {
        vNum.push_back(s[i] - '0');
    }
    sort(vNum.begin(), vNum.end());

    for (int i = 0; i < iSize; ++i)
    {
        answer += vNum[i] * pow(10, i);
    }


    return answer;
}



/* 참고 코드 */
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

long long solution(long long n) {
    long long answer = 0;

    string str = to_string(n);
    sort(str.begin(), str.end(), greater<char>());
    answer = stoll(str);

    return answer;
}

// stoi, stol, stoll  부호 있는 정수를 인식하고 반환
// 반환값의 자료형 차이

int i = stoi(str_i);
long int li = stol(str_li);
float f = stof(str_f);
double d = stod(str_d);
long long s = stoll(str_i);

