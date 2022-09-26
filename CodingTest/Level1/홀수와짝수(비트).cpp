#include <iostream>
#include <vector>
using namespace std;


string solution(int num) {
	string answer = "";
	return num & 1 ? "Odd" : "Even";
}

// & : 비트단위 And 연산
// | : 비트단위 Or 연산
// ^ : 비트단위 XOR 연산 -> 서로 다른 경우 1을 반환 
// ~ : 비트반전


int main()
{

}