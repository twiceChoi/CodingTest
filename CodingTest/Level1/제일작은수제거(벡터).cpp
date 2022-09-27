#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {

    vector<int> answer = arr;
    sort(arr.begin(), arr.end());


    answer.erase(remove(answer.begin(), answer.end(), *arr.begin()), answer.end());

    if (answer.size() == 0)
        answer.push_back(-1);

    return answer;
}

//remove는 특정 값을 찾아서 완전히 지우는 것이 아닌, 벡터의 뒤로 보내기 때문에 추가로 erase를 해줘야 한다.


/* 참고 코드 */
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer = arr;

    int nMin = *min_element(arr.begin(), arr.end());
    int pos = find(answer.begin(), answer.end(), nMin) - answer.begin();
    answer.erase(answer.begin() + pos);

    return answer.empty() ? vector<int>(1, -1) : answer;
}

//max_element(), min_element()는 자료구조에서 [forward, last) 범위 내 최대값, 최소값을 리턴한다.
//이를 활용해서 벡터, 배열의 최대값과 최소값을 출력할 수 있다.