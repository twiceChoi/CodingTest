#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
using namespace std;

//왼쪽괄호와 오른쪽 괄호가 짝을 이루는가 

bool IsWellFormed(const string& s)
{
	/* 해당 짝 */
	unordered_map<char, char> keyvalue = {
		{'(',')' },{'{','}' }, {'[',']'}
	};
	
	stack<char> Key;

	for (int i = 0; i < s.size(); ++i)
	{
		//마지막에 넣은 거와 방금 넣은게 짝이 맞다면 팝
		//그게 아니라면 푸쉬한다.
		//중간 결과를 저장해야 하기 때문에 stack을 사용한다.
		if (!Key.empty() && keyvalue[Key.top()] && keyvalue[Key.top()] == s[i])
			Key.pop();
		else
			Key.push(s[i]);
	}
	if (Key.empty())
		return true;

	return false;

	//return empty(Key); 로 변환가능
}

void main()
{
	string s = "([()])[]{()}";
	
	cout << IsWellFormed(s) << endl;
}