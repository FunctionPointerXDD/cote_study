/**
 * 61. 특정 수 만들기(DFS : MS 인터뷰)
 * 3갈래로 트리를 뻗는다.
 */
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <string>

using namespace std;

struct element{
	int num;
	int check;
};

int cnt;
int m;
int n;

int _arr[11];

void dfs(size_t depth, std::vector<element> &arr)
{
	if (depth == arr.size())
	{
		int n = 0;
		size_t i = 1;
		while (i < arr.size())
		{
			if (arr[i].check == 1)
				n += arr[i].num;
			else if(arr[i].check == -1)
				n -= arr[i].num;
			i++;
		}
		if (n == m) cnt++;
		
		return;
	}

	arr[depth].check = 1;	
	dfs(depth + 1, arr);
	arr[depth].check = 0;
	dfs(depth + 1, arr);
	arr[depth].check = -1;
	dfs(depth + 1, arr);
}

void _dfs(int depth, int val)
{
	if (depth == n + 1)
	{
		if (val == m)
			cnt++;
		return;
	}
	_dfs(depth + 1, val + _arr[depth]);
	_dfs(depth + 1, val - _arr[depth]);
	_dfs(depth + 1, val);
}


int main(void)
{
    //freopen("input.txt", "rt", stdin);
	cin >> n >> m;

	// vector<element> arr(n + 1);
	// for (int i = 1; i <= n; ++i)
	// {
	// 	cin >> arr[i].num;
	// 	arr[i].check = false;
	// }

	for (int i = 1; i <= n; ++i)
		cin >> _arr[i];

	// dfs(1, arr);
	_dfs(1, 0);

	if (cnt > 0)
		cout << cnt << endl;
	else
		cout << -1 << endl;

    return 0;
}
