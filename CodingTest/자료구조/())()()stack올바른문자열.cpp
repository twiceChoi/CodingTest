#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
using namespace std;

//���ʰ�ȣ�� ������ ��ȣ�� ¦�� �̷�°� 

bool IsWellFormed(const string& s)
{
	/* �ش� ¦ */
	unordered_map<char, char> keyvalue = {
		{'(',')' },{'{','}' }, {'[',']'}
	};
	
	stack<char> Key;

	for (int i = 0; i < s.size(); ++i)
	{
		//�������� ���� �ſ� ��� ������ ¦�� �´ٸ� ��
		//�װ� �ƴ϶�� Ǫ���Ѵ�.
		//�߰� ����� �����ؾ� �ϱ� ������ stack�� ����Ѵ�.
		if (!Key.empty() && keyvalue[Key.top()] && keyvalue[Key.top()] == s[i])
			Key.pop();
		else
			Key.push(s[i]);
	}
	if (Key.empty())
		return true;

	return false;

	//return empty(Key); �� ��ȯ����
}

void main()
{
	string s = "([()])[]{()}";
	
	cout << IsWellFormed(s) << endl;
}