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

/* 참고 풀이 : 가우스의 공식 : 2번타는거면 2배니까  1+ 2+ 3+ 4 나 같은 공식*/
using namespace std;
typedef long long ll;

long long solution(int price, int money, int count)
{
    ll answer = (ll)(count * (count + 1) / 2) * price;
    return answer > money ? answer - money : 0;
}

//1부터 n까지의 합은 n * (n+1) / 2 로 구할 수 있습니다