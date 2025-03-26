/**
 * 56. 재귀함수 분석
 */
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <string>

using namespace std;


void recur(int n)
{
	if (n == 0) return;

	recur(n - 1);
	cout << n << ' ';
}

int main(void)
{
    //freopen("input.txt", "rt", stdin);
	int n;
	cin >> n;

	recur(n);
			
    return 0;
}