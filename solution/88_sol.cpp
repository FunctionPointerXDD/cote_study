/**
 * 88. 미로의 최단거리 통로(BFS 활용)
 * 1: 벽, 0: 도로
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int map[7][7];
int dist[7][7]; // 출발지로 부터 해당 위치까지의 거리를 저장하는 용도!
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void bfs(int x, int y)
{
	queue<pair<int, int>> Q;
	Q.push({x, y});
	map[x][y] = 1;

	while(!Q.empty())
	{
		int nx = Q.front().first;
		int ny = Q.front().second;
		Q.pop();

		for (int i = 0; i < 7; ++i)
		{
			int _x = nx + dx[i];
			int _y = ny + dy[i];
			if (_x >= 0 && _x < 7 && _y >= 0 && _y < 7)
			{
				if (map[_x][_y] == 0)
				{
					map[_x][_y] = 1; //우선적으로 탐색한 경로를 체크해준다.
					Q.push({_x, _y});	
					dist[_x][_y] = dist[nx][ny] + 1; // 현재 위치까지의 거리 + 이동 방향(+1)
				}
			}
		}
	}
}

int main(void)
{
	//freopen("input.txt", "rt", stdin);
	for (int i = 0; i < 7; ++i)
	{
		for (int j = 0; j < 7; ++j)
			cin >> map[i][j];
	}

	bfs(0, 0);
	cout << dist[6][6] << endl;

	return 0;
}