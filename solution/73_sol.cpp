/**
 * 73. 최대힙(priority_queue: 우선순위 큐)
 * c++에서 priority_queue는 max_heap이 기본이다.
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


int main(void)
{
	//freopen("input.txt", "rt", stdin);
	priority_queue<int> Q;	
	int n;

	while (1)
	{
		cin >> n;
		if (n == -1)
			break;
		if (n == 0)
		{
			if (!Q.empty())
			{
				cout << Q.top() << '\n';
				Q.pop();
			}
			else
				cout << -1 << '\n';
		}
		Q.push(n);
	}

	return 0;
}
