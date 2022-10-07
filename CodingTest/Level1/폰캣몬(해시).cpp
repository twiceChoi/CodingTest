#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

bool SecondSort(pair<int, int>a, pair<int, int> b)
{
    if (a.second < b.second)
        return true;

    return false;
}
/* 나의 풀이 */
int solution(vector<int> nums)
{
    int answer = 0;
    int SumPocket = 0;
    //골라야 하는 마리 수
    int size = nums.size() / 2;

    //포캣몬 종류가 키값, 종류의 마리수가 값
    unordered_map<int, int> pocket_name_num;

    for (int i = 0; i < nums.size(); ++i)
        ++pocket_name_num[nums[i]];

    vector<pair<int, int>> vPocket(pocket_name_num.begin(), pocket_name_num.end());
    sort(vPocket.begin(), vPocket.end(), SecondSort);


    for (auto& pocket : vPocket)
    {
        ++answer;
        SumPocket += pocket.second;
        if (SumPocket >= size)
            return answer;
    }

    return answer;
}

void main()
{
    vector<int> nums;
    nums.emplace_back(3);
    nums.emplace_back(3);
    nums.emplace_back(3);
    nums.emplace_back(2);
    nums.emplace_back(2);
    nums.emplace_back(4);
    cout << solution(nums) << endl;
}


/* map 을 vector로 바꿔서 소팅하는 방법 */

//unordered map을 value 기준으로 정렬
//bool cmp(pair<string, int>& a, pair<string, int>& b)
//{
//    return a.second < b.second;
//}
//
//int main()
//{
//    unordered_map<string, int> map;
//
//    map["a"] = 6;
//    map["b"] = 1;
//    map["c"] = 4;
//    map["d"] = 8;
//
//    vector<pair<string, int>> vec(map.begin(), map.end()); // map을 vector로 변경
//    sort(vec.begin(), vec.end(), cmp);
//
//    for (auto elem : vec)
//    {
//        cout << elem.first << endl;
//    }
//}


/* 참고 풀이 */

int solution(vector<int> nums) {
    unordered_set<int> s(nums.begin(), nums.end());

    return min(nums.size() / 2, s.size());
}