/**
 * 64. 경로 탐색(DFS)
 */
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <string>

using namespace std;


int map[21][21]; //정점간의 연결을 표시하는 2차원 배열
int visited[21]; //지나간 정점

int cnt;
int n, m;

void dfs(int v)
{
	if (v == n)
	{
		cnt++;
		return;
	}

	for (int i = 1; i <= n; ++i)
	{
		// v 정점에서 i 정점으로 간다고 생각!
		if (map[v][i] == 1 && visited[i] == 0)
		{
			visited[i] = 1; // 방문한 정점 체크
			dfs(i); // 이동하는 방향의 정점을 인자로 넘겨서 호출
			visited[i] = 0;// 다시 돌아와서 체크한 정점 위치를 푼다.
		}
	}

}

int main(void)
{
	freopen("input.txt", "rt", stdin);
	cin >> n >> m;

	int v1, v2;

	for (int i = 0; i < m; ++i)
	{
		cin >> v1 >> v2;
		map[v1][v2] = 1; // 방향 그래프
		//map[v2][v1] = 1; // 이것 까지 입력하면 양방향 그래프
	}

	visited[1] = 1;
	dfs(1);

	cout << cnt << endl;

	return 0;
}

