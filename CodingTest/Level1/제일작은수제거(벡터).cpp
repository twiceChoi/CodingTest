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

//remove�� Ư�� ���� ã�Ƽ� ������ ����� ���� �ƴ�, ������ �ڷ� ������ ������ �߰��� erase�� ����� �Ѵ�.


/* ���� �ڵ� */
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

//max_element(), min_element()�� �ڷᱸ������ [forward, last) ���� �� �ִ밪, �ּҰ��� �����Ѵ�.
//�̸� Ȱ���ؼ� ����, �迭�� �ִ밪�� �ּҰ��� ����� �� �ִ�.