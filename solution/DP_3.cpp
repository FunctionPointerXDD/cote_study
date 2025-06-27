/**
 * DP_3 최대 부분 증가수열(LIS)
 *  이중 for문으로 구현한다.
 *  배열을 처음부터 순회하면서, 만나는 배열값이 마지막 항으로 가정하고 만들 수 있는 최대 수열의 값을 구한다.
 *  이 때, 최대 길이를 저장할 배열을 만들어서 거기에다 저장한다. (메모이제이션)
 *  --> 그리고 비교연산시 길이를 저장한 배열을 참조하면 첫번째 배열까지 순회할 필요가 없다.
 */
 #include <iostream>
 #include <string>
 #include <vector>
 #include <algorithm>

 using namespace std;

 int dp[1001];

 int main(void)
 {
	int n;	
	cin >> n;
	vector<int> arr(n + 1), dp(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> arr[i];

	dp[1] = 1; //첫번째 길이는 반드시 1이다.

	int res = 0;
	for (int i = 2; i <= n; ++i)
	{
		int max = 0; //이전 배열을 순회했을때 최대 길이
		for (int j = i - 1; j >= 1; --j)
		{
			if (arr[i] > arr[j] && max < dp[j])
				max = dp[j];
		}
		dp[i] = max + 1; //현재 위치에서 최대 길이를 저장한다. (+1은 자신의 값을 포함)
		if (res < dp[i])
			res = dp[i]; //각 위치에서 최대 길이값을 비교해서 전체 최댓값을 구한다.
	}

	cout << res << endl;
	return 0;
 }
