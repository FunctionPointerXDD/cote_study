/**
 * 72. 공주 구하기(큐 자료구조로 해결)
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


int main(void)
{
	//freopen("input.txt", "rt", stdin);
	int n, k, cnt;
	cin >> n >> k;

	queue<int> Q;
	for (int i = 0; i < n; ++i)
		Q.push(i + 1);

	cnt = 0;
	while (Q.size() > 1)
	{
		cnt++;
		if (cnt == k)
		{
			Q.pop();
			cnt = 0;
		}
		else
		{
			Q.push(Q.front());
			Q.pop();
		}
	}
	cout << Q.front() << endl;

	return 0;
}
