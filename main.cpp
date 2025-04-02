/**
 * 90. 라이언 킹 심바(삼성 SW역량평가 기출: BFS활용) 난이도 상
 * 
 * 구현 + BFS 문제다. 문제를 이해한 것을 BFS방식으로 잘 구현해야 한다.
 * 나는 이 문제를 처음 접했을 때, 문제를 이해하는 데 시간이 오래걸렸고,
 * 이해를 했으나, 구현하는 방법에서 많이 헤맸다.
 * 
 * 핵심은 큐에 넣을 수 있는 경우의 수(State)와 심바의 상태 정보(Simba)를 분리해서 구현하는 것이다!
 * 심바의 현재 위치마다 토끼를 만날 수 있는 최단 거리를 반복해서 구하는 것이다.
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
	State(int a, int b) : row(a), col(b) {}

	//최소 힙
	bool operator<(const State &p) const
	{
		// if (dist == p.dist)
		// {
		// 	if (row == p.row) return col > p.col;
		// 	else return row > p.row;
		// }
		// else return dist > p.dist;

		if (dist != p.dist) return dist > p.dist;
		if (row != p.row) return row > p.row;
		else return col > p.col;
	}
};

struct Simba {
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
int check[25][25];
int t;

int main(void)
{
	cin >> n;

	return 0;
}
