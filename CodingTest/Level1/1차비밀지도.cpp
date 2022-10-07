#include <string>
#include <vector>
#include <iostream>
#include <bitset>
using namespace std;

/* 내가 짠 코드 */
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<char> answerTemp;
    vector<int> arr;

    /* 여기서 따로 arr만들지 않아도 될거 같다.arr1에 대입해주는게 좀더 효율적 */
    for (int i = 0; i < arr1.size(); ++i)
        arr.push_back( arr1[i] | arr2[i]);
    

    int iDigitNum = 0;
    string s = "";
    for (int i = 0; i < n; ++i)
    {
        /* 이진으로 변환 */
        iDigitNum = 0;
        s = "";
        while (arr[i] > 0)
        {
            if (arr[i] % 2)
                answerTemp.push_back('#');
            else
                answerTemp.push_back(' ');

            ++iDigitNum;
            arr[i] /= 2;
        }
        while (iDigitNum < n)
        {
            answerTemp.push_back(' ');
            ++iDigitNum;
        }
        while (answerTemp.size() > 0)
        {
            s += answerTemp.back();
            answerTemp.pop_back();
        }
        answer.push_back(s);
    }

    return answer;
}

void main()
{
    vector<int> arr1;
    arr1.push_back(9);
    arr1.push_back(20);
    arr1.push_back(28);
    arr1.push_back(18);
    arr1.push_back(11);
    vector<int> arr2;
    arr2.push_back(30);
    arr2.push_back(1);
    arr2.push_back(21);
    arr2.push_back(17);
    arr2.push_back(28);

   
    cout << solution(5, arr1, arr2)[0] << endl;
    cout << solution(5, arr1, arr2)[1] << endl;
    cout << solution(5, arr1, arr2)[2] << endl;
    cout << solution(5, arr1, arr2)[3] << endl;
}


/* 참고 코드 : 비트 연산 */
#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for (int i = 0; i < n; i++) {
        arr1[i] = arr1[i] | arr2[i];
        string ans = "";
        for (int j = 0; j < n; j++) {
            if (arr1[i] % 2 == 0) ans = " " + ans;
            else ans = "#" + ans;
            arr1[i] = arr1[i] >> 1;
        }
        answer.push_back(ans);
    }
    return answer;
}
