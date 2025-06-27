/**
 * DP_9 플로이드 워샬 알고리듬
 * 모든 정점에서 다른 모든 정점으로 갈 때 비용의 최소값을 구하는 문제이다.
 * 다익스트라 알고리듬과 동일한 결과를 얻지만, 구현 방식이 DP를 사용해서 더 간결하다.
 * 다만 성능면에서 큰 차이는 없다. 만약, 정점의 개수가 매우 많은 경우 다익스트라가 더 적절할 수 있다ㅐ
 * 
 * 구현 방식은 보통 3중 for문을 사용해서 구현한다.
 * dp[i][j]: i정점에서 j정점으로 갈 때 드는 최소 비용
 * 
 * i -> i 처럼 자기 자신으로 가는 비용은 0
 * 만약 다른 정점으로 이동이 불가하다면 M으로 처리한다.
 * 
 * dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
 * 							k정점을 경유해서 가는 것이 더 최소라면 그것을 선택
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
	int n, m; // n: vectexs, m: edges
	cin >> n >> m;

	vector<vector<int>> map(n + 1, vector<int> (n + 1, INT_MAX / 2)); // INT_MAX / 2 -> protect overflow

	for (int i = 1; i <= n; i++)
		map[i][i] = 0;

	int a, b, c;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b >> c;
		map[a][b] = c;
	}

	// 플로이드-와샬 알고리듬
	// 경유하는 정점 k를 순서대로 최소가 되는 지 검사하는 방식으로 해야한다.
	// 만약 중첩된 for문에서 k값을 돌릴 경우, 이전 결과를 중복해서 계산되는 경우가 발생한다.
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] == (INT_MAX / 2))
				cout << 'M' << ' ';
			else
				cout << map[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}