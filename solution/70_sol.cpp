/**
 * 70. 그래프 최단거리(BFS)
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


int check[21];
int dist[21]; // 최소 거리를 저장하는 용도 (배열의 인덱스가 정점을 의미)
vector<int> graph[21];

int main(void)
{
	freopen("input.txt", "rt", stdin);
	int n, m;

	cin >> n >> m;

	int a, b;
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b;
		graph[a].push_back(b);
	}

	queue<int> Q;
	//1번 정점을 초기화
	Q.push(1);
	check[1] = 1;

	while (!Q.empty())
	{
		int x = Q.front();
		Q.pop();
		for (size_t i = 0; i < graph[x].size(); ++i)
		{
			if (check[graph[x][i]] == 0)
			{
				check[graph[x][i]] = 1;
				Q.push(graph[x][i]);
				dist[graph[x][i]] = dist[x] + 1;
				// x 정점에서 i 정점으로 이동한다는 사실을 잊지 말자.
			}
		}
	}

	for (int i = 2; i <= n; ++i)
	{
		cout << i << " : " << dist[i] << '\n';
	}

	return 0;
}
