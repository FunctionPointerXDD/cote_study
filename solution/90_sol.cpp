/**
 * 90. 라이언 킹 심바(삼성 SW역량평가 기출: BFS활용) 난이도 상
 * 
 * 구현 + BFS 문제다. 문제를 이해한 것을 BFS방식으로 잘 구현해야 한다.
 * 나는 이 문제를 처음 접했을 때, 문제를 이해하는 데 시간이 오래걸렸고,
 * 이해를 했으나, 구현하는 방법에서 많이 헤맸다.
 * 
 * 핵심은 큐에 넣을 수 있는 경우의 수(State)와 심바의 상태 정보(Simba)를 분리해서 구현하는 것이다!
 * 심바의 위치가 변경될 때 마다 토끼를 만날 수 있는 최단 거리를 반복해서 구하는 것이다.
 * 
 * 심바를 기준으로 계속 상하좌우로 갈 수 있는 위치를 
 * 우선순위 큐에 삽입하면서 토끼가 나오기 전까지 이동 거리를 기록한다.
 * 
 * 그러다가 만약 큐에서 나온 위치가 토끼가 있는 위치일 때
 * 심바의 상태를 업데이트 및 큐를 모두 비우고, 이전에 체크한 위치를 다시 0으로 초기화 한다.
 * -> 이유는 토끼가 나오기 전까지 기록한 정보는 기존 심바가 있던 위치에서 최단거리로 갈 수 있는 정보를 기록한 것이기 때문이다.
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct State {
	int dist;
	int row;
	int col;
	State(int d, int a, int b) : dist(d), row(a), col(b) {}

	bool operator<(const State &p) const
	{
		// apply Min Heap
		if (dist != p.dist) return dist > p.dist;
		if (row != p.row) return row > p.row;
		else return col > p.col;
	}
};

struct Lion{
	int x;
	int y;
	int size;
	int eat;

	void update()
	{
		eat = 0;
		size++;
	}
};

int n;
int map[25][25];
bool check[25][25];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int bfs(priority_queue<State> &Q, Lion &lion)
{
	int ret = 0;

	Q.push(State(0, lion.x, lion.y));
	check[lion.x][lion.y] = 1;

	while (!Q.empty())
	{
		State tmp = Q.top();
		Q.pop();
		int dist = tmp.dist;
		int x = tmp.row;
		int y = tmp.col;

		if (map[x][y] != 0 && map[x][y] < lion.size)
		{
			map[x][y] = 0;

			lion.eat++;
			if (lion.eat >= lion.size)
				lion.update();
			for (int i = 0; i < n; ++i)	
			{
				for (int j = 0; j < n; ++j)
					check[i][j] = 0;
			}
			while (!Q.empty()) 
				Q.pop();
			ret = dist;
		}

		for (int i = 0; i < 4; ++i)
		{
			int _x = x + dx[i];
			int _y = y + dy[i];
			if (_x >= 0 && _x < n && _y >= 0 && _y < n)
			{
				if (!check[_x][_y] && map[_x][_y] <= lion.size)
				{
					Q.push(State(dist + 1, _x, _y)); //한 칸씩 이동하는 경로 마다 dist를 1씩 늘려줌.
					check[_x][_y] = 1;
				}
			}
		}
	}

	return ret;
}

int main(void)
{
	//freopen("input.txt", "rt", stdin);
	Lion simba;
	priority_queue<State> Q;

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> map[i][j];
			if (map[i][j] == 9)
			{
				simba.x = i;
				simba.y = j;
				simba.size = 2;
				simba.eat = 0;
				map[i][j] = 0;
				check[i][j] = 1;
			}
		}
	}
	int time = bfs(Q, simba);

	cout << time << endl;
	return 0;
}
