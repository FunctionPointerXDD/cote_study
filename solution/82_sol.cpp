/**
 * 82. 순열구하기(DFS)
 */
 #include <iostream>
 #include <algorithm>
 #include <vector>

 using namespace std;

 int arr[16];
 int check[16];
 int output[16];
 int n, r;
 int cnt;

 // depth가 선택하는 원소의 개수면서 동시에 선택의 순서다.
 void dfs(int depth)
 {
	if (depth == r) // 3개가 선택되었을 때 쓴다.
	{
		for (int i = 0; i < r; ++i)
			cout << output[i] << ' ';
		cout << '\n';
		cnt++;
		return;
	}

	for (int i = 1; i <= n; ++i)
	{
		if (check[i] == 0)
		{
			check[i] = 1;
			output[depth] = arr[i];
			dfs(depth + 1);
			check[i] = 0;
		}
	}
 }

 int main(void)
 {
	freopen("input.txt", "rt", stdin);
	cin >> n >> r;

	vector<int> vec;

	for (int i = 1; i <= n; ++i)
		cin >> arr[i];
	
	dfs(0); // depth를 0부터 시작한다. 3개가 선택되었다는 것을 쉽게 표현하기 위해서다.

	cout << cnt << endl;

	return 0;
 }