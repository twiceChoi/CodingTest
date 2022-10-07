#include <string>
#include <vector>

using namespace std;

/* brown: 갈색 격자의 수 red : 노란 격자의 수 */
vector<int> solution(int brown, int red) {

    int len = brown / 2 - 1;

    int w = len - 3;
    int h = 3;

    while (w >= h) {
        if (w * h == (brown + red)) break;

        w--;
        h++;
    }

    return vector<int>{w, h};
}