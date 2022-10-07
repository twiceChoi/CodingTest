#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    //������ ���ǻ��� ����� �𸣴°� �����̴�.
    //������ �����ؾ� �Ѵ�. 
    //Ű���� �ǻ��� ������ ���� ���� Ƚ���� ���� ��Ų��. 

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