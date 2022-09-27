#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/* 내가 짠 코드 */

/* sort는 인자 2개받는 조건자 */
bool StringSort(string string1, string string2)
{
    if (stoll(string1) > stoll(string2))
        return false;/* false 일경우 change */
    else
        return true; /* true 일경우 안바꾼다 */
}

string solution(string s) {
    string answer = "";
    vector<string>vNum;
  
    for (int i = 0; i < s.size(); ++i)
    {
        string answer = "";
        while (true)
        {
            answer += s[i];
            ++i;
            if (i == s.size() || s[i] == ' ') /* 맨끝을 고려해서 짜자 */
            {
                vNum.push_back(answer);
                break;
            }
            
        }
    }
    sort(vNum.begin(), vNum.end(), StringSort);

    answer += *vNum.begin();
    answer += ' ';
    answer += *(vNum.end() - 1);
    
    return answer;
}

void main()
{
    string s = "11 22 33 -4";
    cout << solution(s) << endl;
}