/**
 * 65. 미로탐색(DFS) -> 2차원 배열을 dfs로 경로탐색
 * 
 * 2차원 배열의 각 지점이 모두 정점(vertex)을 의미한다. 만약 4 x 4 배열이라면 총 16개의 정점이 존재한다.
 * (정점간의 연결을 2차원 배열로 표시하는 것과는 전혀 다른 것임을 인지!!)
 * 그러므로 2차원 배열의 각 지점에서 다른 곳을 이동할 때 마다 재귀호출을 해서 넘어간다!
 */

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <string>

using namespace std;

int map[9][9];
int check[9][9];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1}; //E, W, S, N

int cnt;

//v -> i
void dfs(int row, int col)
{
	if (row == 7 && col == 7)
	{
		cnt++;
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		int _row = row + dy[i];
		int _col = col + dx[i];
		if (map[_row][_col] == 0 && check[_row][_col] == 0)
		{
			check[_row][_col] = 1;
			dfs(_row, _col);
			check[_row][_col] = 0;
		}
	}
}

int main(void)
{
	//freopen("input.txt", "rt", stdin);

	for (int i = 0; i <= 8; ++i)
	{
		for (int j = 0; j <= 8; ++j)
			map[i][j] = 1;
	}

	for (int i = 1; i <= 7; ++i)
	{
		for (int j = 1; j <= 7; ++j)
			cin >> map[i][j];
	}

	check[1][1] = 1;
	dfs(1, 1);

	cout << cnt << endl;
	return 0;
}
