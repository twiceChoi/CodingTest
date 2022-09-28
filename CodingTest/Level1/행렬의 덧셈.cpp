#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* 나의 풀이 */
vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
  
    for (int i = 0; i < (arr1.size()); ++i)
    {
        vector<int>answer1;
        for (int j = 0; j < (arr1[0].size()); ++j)
        {
            answer1.push_back(arr1[i][j] + arr2[i][j]); 
           
        }
        answer.push_back(answer1);
        answer1.clear();
    }

    return answer;
}


void main()
{
    vector<int> arr_1;
    vector<int> arr_2;
    vector<vector<int>> arr1;

    arr_1.push_back(1);
    arr_1.push_back(2);
    arr_2.push_back(2);
    arr_2.push_back(3);

    arr1.push_back(arr_1);
    arr1.push_back(arr_2);
   
    vector<int> arr_3;
    vector<int> arr_4;
    vector<vector<int>> arr2;
    arr_3.push_back(3);
    arr_3.push_back(4);
    arr_4.push_back(5);
    arr_4.push_back(6);

    arr2.push_back(arr_3);
    arr2.push_back(arr_4);

    cout << solution(arr1, arr2)[0][0]<< endl;
    cout << solution(arr1, arr2)[0][1] << endl;
    cout << solution(arr1, arr2)[1][0] << endl;
    cout << solution(arr1, arr2)[1][1] << endl;

}