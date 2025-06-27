/**
 * DP_7 동전교환
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

	int n, m; //동전 종류 개수, 거슬러 줄 금액
	cin >> n;
	vector<int> coins(n + 1); // 동전 종류
	for (int i = 1; i <= n; ++i)
		cin >> coins[i];
	cin >> m;

	//거슬러 줄 동전개수 최대값으로 초기화
	vector<int> dp(m + 1, INT_MAX);
	//0원을 거슬러주는 동전 개수는 0개이다.
	dp[0] = 0;

	// dp[j] : j 만큼의 금액을 거슬러 주는데 필요한 동전의 최소 개수. (가장 중요한 정의)
	for (int i = 1; i <= n; ++i)
	{
		for (int j = coins[i]; j <= m; ++j)
		{
			// j 는 동전 종류들의 합으로 나타 낼수 있다.
			// 그러므로 i 종류의 동전이 사용된 경우와 그렇지 않은 경우로 나누어서 볼 수 있다.
			// 만약 i 종류의 동전이 사용되었다면,
			// i 종류의 동전을 사용하기 이전의 최소 동전 개수의 값(dp[j - coins[i]])과, 
			// 현재 추가되는 동전(coins[i])을 하나 추가해준다. ( + 1)
			dp[j] = min(dp[j], dp[j - coins[i]] + 1);
			//       동전이 사용되지 않은 경우, 동전이 사용된 경우 중 최소 개수

			//이전에 내가 생각했던 점화식 (조금 비효율적이다. 그냥 거스름돈을 동전 종류들의 합으로 표현할 수 있다는 사실을 알아야 한다.)
			//-> dp[j] = min(dp[j], j / coins[i] + dp[j % coins[i]]);
		}
	}

	cout << dp[m] << endl;

	return 0;
}