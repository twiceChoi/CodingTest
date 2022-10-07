#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    //지금은 각의상이 몇개인지 모르는게 문제이다.
    //개수를 누적해야 한다. 
    //키값을 의상의 종류로 값은 나온 횟수를 누적 시킨다. 

    unordered_map<string, int> cloth_sort_num;
    for (int i = 0; i < clothes.size(); ++i)
    {
        ++cloth_sort_num[clothes[i].back()];
    }

    for (auto& iter : cloth_sort_num)
    {
        answer *= (iter.second + 1);
    }

    return answer - 1;
}

void main()
{
    vector<vector<string>> clothes;
    vector<string> vs;
    vs.emplace_back("yellow_hat");
    vs.emplace_back("headgear");
    clothes.emplace_back(vs);
    vs.clear();

    vs.emplace_back("blue_sunglasses");
    vs.emplace_back("eyewear");
    clothes.emplace_back(vs);
    vs.clear();

    vs.emplace_back("green_turban");
    vs.emplace_back("headgear");
    clothes.emplace_back(vs);
    vs.clear();

    cout << solution(clothes) << endl;
}