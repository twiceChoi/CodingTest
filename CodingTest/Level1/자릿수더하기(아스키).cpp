#include <iostream>

/* ���� Ǯ�� */
using namespace std;
int solution(int n)
{
    int answer = 0;

    while (true)
    {
        answer += n % 10;
        n = n / 10;

        if (n < 1)
            break;
    }

    return answer;
}


/* ���� Ǯ�� */
#include <iostream>
#include <string>

using namespace std;
int solution(int n)
{
    int answer = 0;

    string s = to_string(n);

    //s.size() �� ���ڿ� ���� 
    for (int i = 0; i < s.size(); i++) 
        answer += (s[i] - '0');


    return answer;
}

//to_string(����) ���ڸ� ��Ʈ�� Ÿ������ 

//string �� ��� length() �� size() �� ����. 
//string ���� �迭ó�� �ε����� ������ �����ϴ�. 
//�ε����� �����Ͽ� �ٲ�ġ�⵵ ����


/* �ƽ�Ű �ڵ带 �̿��Ͽ� char���� int ������ ��ȯ */
//�ش� ������ ascii �ڵ� ���� ������ ����Ǿ��ִ�.
//48 ������ ���� 0 ~ 9�� �Ҵ��ϰ� �ִ�.



//���ڷ� ���� ������ ���ڸ� ��� ��� 

char c = '1';
int n = c - 48;

//n�� ������ ���� 1�� ���� �� �ִ�. 

char c = '1';
int n = c - '0';
