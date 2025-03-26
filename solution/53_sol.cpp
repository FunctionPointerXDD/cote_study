/**
 * 53. K진수 출력(스택 자료구조 직접 구현)
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>

using namespace std;

const char *_hex = "0123456789ABCDEF";

int main(void)
{
	//freopen("input.txt", "rt", stdin);	
	int n, k;

	cin >> n >> k;
	stack<char> base;

	int tmp = n;
	int mod;
	while (tmp > 0)
	{
		mod = tmp % k;
		base.push(_hex[mod]);
		tmp /= k;
	}

	while (!base.empty())
	{
		cout << base.top();
		base.pop();
	}
	cout << endl;

	return 0;
}
