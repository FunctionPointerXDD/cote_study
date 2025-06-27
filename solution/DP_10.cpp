/**
 * DP_10 회장뽑기 (플로이드-워샬 응용)
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;


int main(void)
{
	freopen("input.txt", "rt", stdin);
	int n;
	cin >> n; // 회원 수

	vector<vector<int>> dist(n + 1, vector<int> (n + 1, 1000));
	for (int i = 1; i <= n; i++) 
		dist[i][i] = 0;

	int a, b;
	while (1)
	{
		cin >> a >> b;
		if (a == -1 || b == -1) break;
		//친구간의 간선 비용은 1이다.
		dist[a][b] = 1;
		dist[b][a] = 1;
	}
	//정점 그래프를 그림으로 그려보면 이해가 빠르다.
	//만약 dist[1][3] 은 1000으로 되어있고, dist[1][2] == 1 && dist[2][1] == 1 이라면
	// dist[1][3] 은 2가 된다.
	// 이 말은 1번 회원에게 친구의 친구인 관계를 가지고 있다느느 의미이다.

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	// for (int i = 1; i <= n; i++)
	// {
	// 	for (int j = 1; j <= n; j++)
	// 	{
	// 		cout << dist[i][j] << ' ';
	// 	}
	// 	cout << '\n';
	// }

	//각 행 i번 친구 j번 관계의 최대값이 i번 회원의 점수다. (문제에서 설명하는 친구의 친구가 2점, 바로 친구인 경우 1점 이런 식이다..)
	vector<int> master(n + 1);
	int score = INT_MAX;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			master[i] = max(dist[i][j], master[i]);
		}
		score = min(score, master[i]);
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (score == master[i]) cnt++;
	}

	cout << score << ' ' << cnt << '\n';
	for (int i = 1; i <= n; i++) {
		if (master[i] == score)
			cout << i << ' ';
	}
	cout << endl;

	return 0;
}