/**
 * 위상 정렬
 * 어떤 일을 하는 순서를 찾는 알고리듬이다.
 * 
 * 일의 순서임으로 방향그래프로 표현이 가능하다.
 * 1차원 배열의 인덱스를 정점으로 삼고, 해당 정점까지 가는데 선행되어야 할 정점의 개수를 증가시킨다.
 * 배열의 값이 0인 것부터 우선적으로 처리한다. (큐를 사용)
 * 큐에서 pop을 할 때 해당 정점 이후의 처리해야 할 정점의 값을 1 감소시킨다.
 * 이러한 과정을 반복하면 큐에서 삽입된 순서대로 작업이 처리된다.
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;


int main(void)
{
	freopen("input.txt", "rt", stdin);

	int n, m;
	cin >> n >> m; // 일의 개수, 일의 순서 정보의 개수

	vector<vector<int>> graph(n + 1, vector<int> (n + 1, 0));
	vector<int> degrees(m + 1); 
	int a, b;
	//order: a -> b
	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b;
		graph[a][b] = 1;
		degrees[b]++;
	}

	queue<int> Q;
	for (int i = 1; i <= m; i++)
	{
		if (degrees[i] == 0) {
			Q.push(i);
		}
	}

	vector<int> res;
	while(!Q.empty())
	{
		int cur = Q.front();
		res.push_back(cur);
		Q.pop();
		for (int i = 1; i <= n; i++)
		{
			if (graph[cur][i] == 1)
			{
				degrees[i]--;
				if (degrees[i] == 0)
					Q.push(i);
			}
		}
	}

	for (size_t i = 0; i < res.size(); i++)
		cout << res[i] << ' ';
	cout << endl;

	return 0;
}
