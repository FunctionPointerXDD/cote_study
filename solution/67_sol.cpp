/**
 * 67. 최소비용(DFS: 인접행렬)
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


vector<pair<int, int>> map[21];
int check[21];
int cost = 2147483647;

int n, m;

void dfs(int v, int sum)
{
	if (v == n)
	{
		//모든 경로의 비용 중 최솟값을 찾는다.
		if (cost > sum)
			cost = sum;
		return;
	}

	for (size_t i = 0; i < map[v].size(); ++i)
	{
		if (check[map[v][i].first] == 0)
		{
			check[map[v][i].first] = 1;
			dfs(map[v][i].first, sum + map[v][i].second);
			check[map[v][i].first] = 0;
		}
	}
}

int main(void)
{
	//freopen("input.txt", "rt", stdin);

	cin >> n >> m;
	int v1, v2, w;

	for (int i = 1; i <= m; ++i)
	{
		cin >> v1 >> v2 >> w;
		map[v1].push_back(make_pair(v2, w));
	}

	//1번 정점에서 출발
	check[1] = 1;
	dfs(1, 0);

	cout << cost << endl;
	return 0;
}
