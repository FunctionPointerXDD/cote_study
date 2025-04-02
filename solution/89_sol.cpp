/**
 * 89. 토마토(BFS 활용)
 * Flood Fill Algorithm
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int date_cnt = -1;
int tomatos;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int bfs(queue<pair<int, int>> &Q, vector<vector<int>> &box)
{
	int sweet_size = Q.size(); //현재 익은 총 토마토 개수
	if (sweet_size == tomatos) return 0;
	else if (sweet_size == 0) return -1;

	int cnt = 0; //현재 확인한 익은 토마토 개수
	int add = 0; // 내일 추가로 익을 토마토 개수
	while(!Q.empty())
	{
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();
		cnt++;
		for (int i = 0; i < 4; ++i)		
		{
			int _x = x + dx[i];
			int _y = y + dy[i];
			if (_x >= 0 && _x < n && _y >= 0 && _y < m)
			{
				if (box[_x][_y] == 0)
				{
					Q.push({_x, _y});
					box[_x][_y] = 1; //미리 푸시한 큐들의 위치를 1로 바꾸어주는 것이 좋고, 이 문제에서는 반드시 그래야 한다.
					add++;
				}
			}
		}
		if (sweet_size == cnt)
		{
			date_cnt++;
			sweet_size += add;
			add = 0;
		}
	}
	if (sweet_size != tomatos)
		return -1;
	return date_cnt;
}

int main(void)
{
	//freopen("input.txt", "rt", stdin);
	cin >> m >> n;
	vector<vector<int>> box(n, vector<int>(m));
	queue<pair<int, int>> Q;
	int tmp;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> tmp;
			box[i][j] = tmp;
			if (tmp != -1)
			{
				tomatos++;
				if (tmp == 1)
					Q.push({i, j});
			}
		}
	}

	int date;

	date = bfs(Q, box);
	cout << date << endl;
	return 0;
}
