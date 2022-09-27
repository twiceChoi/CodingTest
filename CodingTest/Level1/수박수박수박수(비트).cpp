#include <string>
#include <vector>

using namespace std;
/* 나의 풀이*/
string solution(int n) {
    string answer = "";
    string answer1 = "수";
    string answer2 = "박";
    bool arr[n];
    for (int i = 0; i < n; ++i)
    {
        if (i % 2)
            arr[i] = true;
        else
            arr[i] = false;


        if (arr[i])
        {
            answer += answer2;
        }
        else
        {
            answer += answer1;
        }
    }



    return answer;
}

/* 참고풀이 */
#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";

    for (int i = 0; i < n; i++)
        i & 1 ? answer += "박" : answer += "수";

    return answer;
}