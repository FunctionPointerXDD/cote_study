/**
 * DP_5 알리바바와 40인의 도둑
 * 다익스트라와 BFS 우선순위 큐 방식으로 풀이하는 것이 정석적인(?) 방법이다.
 * 그런데 여기서는 이동 방향이 오른쪽과 아래 방향 두 곳으로 한정되어 있기 때문에 DP를 활용해서 간단하고 빠르게 해결할 수 있다.
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;


int main(void)
{
	//freopen("input.txt", "rt", stdin);
	int n;
	cin >> n;
	vector<vector<int>> road(n, vector<int>(n));
	vector<vector<int>> dp(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> road[i][j];
		}
	}
	dp[0][0] = road[0][0]; //처음 시작점 초기화

	//행과 열이 0인 부분을 먼저 쭉 dp배열에 증가하는 방향으로 누적해준다.
	for (int i = 1; i < n; i++) {
		dp[0][i] = dp[0][i - 1] + road[0][i];
		dp[i][0] = dp[i - 1][0] + road[i][0];
	}

	// a. (1, 1)부터 해당 위치로 갈 때, 최소가 되는 비용으로 오는 지를 계산하고 거기에 해당 위치에 비용을 더해준다.
	// b. 위와 같은 방법을 모든 위치에 적용한다.
	// c. 목적지인 (n-1, n-1)의 값을 출력한다.
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
			dp[i][j] = road[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
	}

	cout << dp[n - 1][n - 1] << endl;

	return 0;
}

