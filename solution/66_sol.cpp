/**
 * 66. 경로 탐색(DFS: 인접리스트 방법)
 * vector를 배열로 선언해서 배열위치를 정점의 위치로 정의한다.
 * 그리고 각 벡터(정점)마다 갈 수 있는 정점을 추가한다. -> 이것이 인접리스트 처럼 사용한다고 볼 수 있음.
 */

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <string>

using namespace std;


vector<int> map[21];
int check[21];
int cnt;

int n, m;

void dfs(int v)
{
	if (v == n)
	{
		cnt++;
		return;
	}

	for (size_t i = 0; i < map[v].size(); ++i)
	{
		if (check[map[v][i]] == 0)
		{
			check[map[v][i]] = 1;
			dfs(map[v][i]);
			check[map[v][i]] = 0;
		}
	}
}

int main(void)
{
	freopen("input.txt", "rt", stdin);

	cin >> n >> m;
	int v, e;


	for (int i = 1; i <= m; ++i)
	{
		cin >> v >> e;
		map[v].push_back(e);
	}

	//1번 정점에서 출발
	check[1] = 1;
	dfs(1);

	cout << cnt << endl;
	return 0;
}
