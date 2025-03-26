/**
 * 63. 인접행렬(가중치 방향그래프)
 */
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <string>

using namespace std;


int map[21][21];

int main(void)
{
	freopen("input.txt", "rt", stdin);
	int n, m; // n: vertex(정점), m: edge(간선)
	cin >> n >> m;

	int v1, v2, w; // w: weight(가중치)

	for (int i = 0; i < m; ++i)
	{
		cin >> v1 >> v2 >> w;
		map[v1][v2] = w;
	}


	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
			cout << map[i][j] << ' ';
		cout << '\n';
	}

	return 0;
}

