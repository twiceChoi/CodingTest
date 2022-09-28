#include <iostream>

using namespace std;

/* 이중for문을 이용한 나의 별짓기 */
int main(void) {
    int a;
    int b;
    cin >> a >> b;

    for (int i = 0; i < b; ++i)
    {
        for (int j = 0; j < a; ++j)
        {
            cout << "*";
        }
        cout << endl;
    }


    return 0;
}

