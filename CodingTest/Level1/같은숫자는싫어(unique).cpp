#include <vector>
#include <iostream>

using namespace std;


/* 내코드 */
vector<int> solution(vector<int> arr)
{
    vector<int> answer(1, arr[0]);

    for (int i = 1; i < arr.size(); ++i)
    {
        if (arr[i] == arr[i-1])
            continue;

        answer.push_back(arr[i]);
    }

    return answer;
}

void main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(3);
    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(1);

    cout << solution(arr)[0] << endl;
    cout << solution(arr)[1] << endl;
    cout << solution(arr)[2] << endl;
    cout << solution(arr)[3] << endl;
}

/* 참고코드 */
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr)
{

    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    vector<int> answer = arr;
    return answer;
}

//unique : vector 배열에서 중복되지 않는 원소들을 앞에서부터 채워나가는 함수
//algorithm 헤더

//erase 함수를 이용
//v.erase(v.begin()+s, v.begin()+e) 명령어를 입력하면 [s,e) 원소가 삭제
//v.erase(unique(v.begin(), v.end()), v.end());