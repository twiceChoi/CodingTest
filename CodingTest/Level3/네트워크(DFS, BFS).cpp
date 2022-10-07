#include <string>
#include <vector>
#include <iostream>
using namespace std;

int iN = 0;
int check[200];

void DFS(vector<vector<int>>& computers, int iNum)
{
    //DFS
    check[iNum] = true; //Check

    for (int i = 0; i < iN; ++i)
    {
        if (check[i] == 0 && computers[iNum][i] == 1)
        {
            DFS(computers, i);
        }
    }

   // if (iNum >= iN - 1)
       // return;
}


int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    iN = n;

    //DFS
    for (int i = 0; i < n; ++i)
    {
        if (check[i])
            continue;

        ++answer;

        DFS(computers, i);
    }

    return answer;
}
void main()
{
    int n = 3;
    vector<vector<int>> computers = { {1, 1, 0}, {1, 1, 0}, {0, 0, 1} };
    cout << solution(n, computers) << endl;
}