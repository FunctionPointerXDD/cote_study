/**
 * DP_8 최대점수 구하기(냅색 알고리듬)
 * 문제 하나당 한 번만 풀 수 있다. (중복 풀이 시간 없음)
 * 
 * 냅색 알고리듬은 무제한 (Unbounded) 유형과 제한된 유형으로 나뉜다.
 * 제한된 유형의 풀이는 1차원 배열로 풀이시 항상 뒤에서 부터 dp값을 갱신해준다. (0 / 1 냅색, 2번 이상 중복되는 유형의 냅색)
 * 무제한은 dp의 초기값부터 갱신해주면 된다.
 * 
 * 번외로 fractional 냅색 알고리듬은 비분할 냅색이라고 하는데 나중에 알아보자...
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

	int n, m;
	cin >> n >> m;
	vector<int> score(n + 1);
	vector<int> time(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> score[i] >> time[i];
	vector<int> dp(m + 1); // j 시간안에 얻을 수 있는 최대 점수

	for (int i = 1; i <= n; ++i) {
		// 문제 유형 마다 한 번만 풀이 할 수 있기 떄문에 (0 / 1 냅색)
		// i번째 유형을 풀이 시 뒤에서 부터 갱신해주어야 
		// 이미 i번 유형을 푼 값을 다시 참조해서 갱신하지 않게 된다.
		for (int j = m; j >= time[i]; --j) { 
			dp[j] = max(dp[j], dp[j - time[i]] + score[i]);
		}
	}

	cout << dp[m] << endl;

	return 0;
}