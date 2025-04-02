/**
 * 86. 피자 배달 거리(DFS)
 * 
 * M개의 피자집을 선택했을 때,
 * 각각의 집으로 부터 피자집까지의 거리를 계산해서 가장 최소가 되는 값을 구하는 문제
 * 조합문제라고 볼 수 있다.
 * 모든 경우의 수를 완전탐색 하는 방식으로 풀이
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int n, m;
int res = 2147483647;

vector<pair<int, int>> hs;
vector<pair<int, int>> pz;
int check[100];

int dist(pair<int, int> &a, pair<int, int> &b)
{
	return abs(a.first - b.first) + abs(a.second - b.second);
}

void _dfs(int idx, int cnt)
{
	if (cnt == m)
	{
		int sum = 0;
		for (size_t i = 0; i < hs.size(); ++i)
		{
			int tmp = 0;
			int _min = 2147483647;
			for (size_t j = 0; j < pz.size(); ++j)
			{
				tmp = dist(hs[i], pz[check[j]]);
				if (_min > tmp)
					_min = tmp;
			}
			sum += _min;
		}
		if (res > sum)
			res = sum; 
		return;
	}

	if (idx < static_cast<int>(pz.size()))
	{
		// 조합을 구하기 위한 트릭 (익혀두자)
		check[cnt] = idx;
		_dfs(idx + 1, cnt + 1);
		_dfs(idx + 1, cnt);
	}
}

void dfs(int cnt, int depth)
{
	if (depth == m)
	{
		int sum = 0;
		for (size_t i = 0; i < hs.size(); ++i)
		{
			int tmp = 0;
			int _min = 2147483647;
			for (int j = 0; j < m; ++j)
			{
				tmp = dist(hs[i], pz[check[j]]);
				if (_min > tmp)
					_min = tmp;
			}
			sum += _min;
		}
		if (res > sum)
			res = sum; 
		return;
	}

	// 조합을 구하기 위한 간편공식
	for (size_t i = cnt; i < pz.size(); ++i)
	{
		check[depth] = i;
		dfs(i + 1, depth + 1);
	}
}

int main(void)
{
	//freopen("input.txt", "rt", stdin);
	cin >> n >> m;

	int tmp;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> tmp;
			if (tmp == 1)
				hs.push_back({i, j});
			else if (tmp == 2)
				pz.push_back({i, j});
		}
	}

	//dfs(0, 0);
	_dfs(0, 0);

	cout << res << endl;
	return 0;
}
