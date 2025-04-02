/**
 * 84. 휴가 (삼성 SW역량평가 기출문제: DFS활용)
 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int _max = -2147483648;

void dfs(int v, int sum, std::vector<std::pair<int, int>> &vec)
{
	//날짜가 n + 1 일 때 휴가를 떠나기 때문에 그 날짜를 초과 또는 미만이어서는 안된다!!
	if (v == n + 1)
	{
		if (_max < sum)
			_max = sum;
		return;
	}

	// 현재 날짜(V)부터 상담을 진행하고 상담 기간이 끝난 날로 넘어감.
	if (vec[v].first + v <= n + 1) 
		dfs(vec[v].first + v, sum + vec[v].second, vec);

	// 현재 날짜(v)에 상담 안하고, 다음날(v + 1) 로 넘어감.
	dfs(v + 1, sum, vec);
}

int main(void)
{
	//freopen("input.txt", "rt", stdin);
	cin >> n;

	vector<pair<int, int>> vec(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> vec[i].first >> vec[i].second;

	int sum = 0;
	//첫째날부터 확인
	dfs(1, sum, vec);

	cout << _max << endl;

	return 0;
}
