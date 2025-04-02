/**
 * 87. 섬나라 아일랜드(BFS, DFS)
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n;
int map[22][22];
int check[22][22];
int dx[8] = { 0, 0, 1, -1, 1, -1, 1, -1 }; //대각선도 고려
int dy[8] = { 1, -1, 0, 0, 1, -1, -1, 1 };

void dfs(int x, int y)
{
	check[x][y] = 1; //경로 탐색이 아니므로 지나간 곳은 모두 1로 체크한다.
	//더 이상 지나갈 경로가 존재하지 않으면, 스코프가 닫히면서 리턴하게 된다.

	for (int i = 0; i < 8; ++i)			
	{
		int _x = x + dx[i];
		int _y = y + dy[i];
		if (_x > 0 && _x <= n && _y > 0 && _y <= n)
		{
			if (map[_x][_y] == 1 && check[_x][_y] == 0)
				dfs(_x, _y);
		}
	}
}

// 현재위치에서 이동할 수 있는 위치를 계속 큐에 집어넣고
// 하나씩 빼면서 체크한다.
// 여기서는 체크배열을 만들었지만, 그냥 1로 표시된 위치를 0으로 만들어줘도 된다.
void bfs(int x, int y)
{
	queue<pair<int, int>> Q;
	Q.push({x, y});

	while(!Q.empty())
	{
		int nx = Q.front().first;
		int ny = Q.front().second;
		check[nx][ny] = 1;
		Q.pop();

		for (int i = 0; i < 8; ++i)
		{
			int _x = nx + dx[i];
			int _y = ny + dy[i];
			if (_x > 0 && _x <= n && _y > 0 && _y <= n)
			{
				if (map[_x][_y] == 1 && check[_x][_y] == 0)
					Q.push({_x, _y});
			}
		}
	}

}

int main(void)
{
	//freopen("input.txt", "rt", stdin);
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
			cin >> map[i][j];
	}

	int cnt = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (map[i][j] == 1 && !check[i][j]) 
			{
				//dfs(i, j);
				bfs(i, j);
				cnt++;
			}
		}
	}

	cout << cnt << endl;

	return 0;
}
