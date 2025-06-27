/**
 * DP_6 가방문제
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;


//max: 17kg -> gem: { 3 (4), 4 (5), 7 (10), 8 (11), 9 (13) };

// gem을 한번만 사용할 수 있는 경우 풀이.
// int main(void)
// {
// 	freopen("input.txt", "rt", stdin);
// 	int n, max_w;
// 	cin >> n >> max_w;

// 	//weight, value
// 	vector<int> w(n + 1);
// 	vector<int> v(n + 1);

// 	for (int i = 1; i <= n; i++)
// 		cin >> w[i] >> v[i];

// 	// (n + 1) x (max_w + 1) dp table
// 	vector<vector<int>> dp(n + 1, vector<int>(max_w + 1, 0));

// 	// i : gem type
// 	// j : culmulated weight
// 	// dp[i][j] : max_value
// 	for (int i = 1; i <= n; i++)
// 	{
// 		for (int j = 0; j <= max_w; j++)
// 		{
// 			//not choice i gem
// 			dp[i][j] = dp[i - 1][j];

// 			//choice i gem
// 			if (j >= w[i])
// 				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
// 		}
// 	}

// 	cout << dp[n][max_w] << endl;

// 	return 0;
// }


//무제한(Unbounded) 냅색
int main(void)
{
	freopen("input.txt", "rt", stdin);
	int n, max_w;
	cin >> n >> max_w;

	//weight, value
	vector<int> w(n + 1);
	vector<int> v(n + 1);

	for (int i = 1; i <= n; i++)
		cin >> w[i] >> v[i];

	// (n + 1) x (max_w + 1) dp table
	vector<int> dp(max_w + 1);

	// i : gem type
	// j : culmulated weight
	// dp[j] : max_value
	for (int i = 1; i <= n; i++)
	{
		for (int j = w[i]; j <= max_w; j++)
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
	}

	cout << dp[max_w] << endl;

	return 0;
}