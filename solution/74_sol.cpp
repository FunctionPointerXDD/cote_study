/**
 * 74. 최소힙(priority_queue: 우선순위 큐)
 */
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;


int main(void)
{
	//freopen("input.txt", "rt", stdin);
	priority_queue<int> Q;	
	int n;

	while (1)
	{
		scanf("%d", &n);
		if (n == -1)
			break;
		if (n == 0)
		{
			if (Q.empty())
				printf("-1\n");
			else
			{
				printf("%d\n", -Q.top());
				Q.pop();
			}
		}
		else
			Q.push(-n);
	}

	return 0;
}
