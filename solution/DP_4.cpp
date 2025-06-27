/**
 * DP_4 가장 높은 탑 쌓기
 */
 #include <iostream>
 #include <string>
 #include <vector>
 #include <algorithm>

 using namespace std;

 int dp[101];

 struct Block{
	int w; //밑면
	int h; //높이
	int m; //무게

	Block(int a, int b, int c) : w(a), h(b), m(c) {}

	bool operator<(const Block &rhs) const
	{
		return w > rhs.w;
	}
 };

 int main(void)
 {
	//freopen("input.txt", "rt", stdin);
	int n;	
	cin >> n;
	vector<Block> arr(n + 1, Block(0, 0, 0));
	vector<int> dp(n + 1);

	for (int i = 1; i <= n; ++i)
		cin >> arr[i].w >> arr[i].h >> arr[i].m;

	// 밑면이 큰 순서대로 내림정렬
	sort(arr.begin() + 1, arr.end()); // 정렬할 때 1부터 시작하는 것 주의!! (sort 함수는 기본적으로 0번 인덱스부터 정렬)

	dp[1] = arr[1].h;
	int res = dp[1];
	//무게를 기준으로 감소하는 수열을 찾으면서 해당 최대 높이를 구한다.
	for (int i = 2; i <= n; ++i)
	{
		int max_h = 0;
		for (int j = i - 1; j >= 1; --j)
		{
			if (arr[i].m < arr[j].m && dp[j] > max_h)
				max_h = dp[j];
		}
		dp[i] = max_h + arr[i].h;
		res = max(res, dp[i]);
	}
	cout << res << endl;
	return 0;
 }
