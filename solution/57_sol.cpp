/**
 * 57. 재귀함수 이진수 출력
 */
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <string>

using namespace std;


void recur(int n)
{
	if (n >= 2)
		recur(n / 2);

	cout << n % 2;
}

int main(void)
{
    //freopen("input.txt", "rt", stdin);
	int n;
	cin >> n;

	recur(n);
	cout << endl;
			
    return 0;
}