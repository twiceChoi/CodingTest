using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;
    long long priceSum = 0;

    for (int i = 0; i < count; ++i)
    {
        priceSum += price * (i + 1);
    }


    return money - priceSum < 0 ? priceSum - money : 0;


}

/* ���� Ǯ�� : ���콺�� ���� : 2��Ÿ�°Ÿ� 2��ϱ�  1+ 2+ 3+ 4 �� ���� ����*/
using namespace std;
typedef long long ll;

long long solution(int price, int money, int count)
{
    ll answer = (ll)(count * (count + 1) / 2) * price;
    return answer > money ? answer - money : 0;
}

//1���� n������ ���� n * (n+1) / 2 �� ���� �� �ֽ��ϴ�