/**
 * 60. 합이 같은 부분집합(DFS: 아마존 인터뷰)
 */
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <string>

using namespace std;

struct element{
	int num;
	bool check;
};

void dfs(size_t depth, std::vector<element> arr)
{
	if (depth == arr.size())
	{
		int n1 = 0, n2 = 0;
		size_t i = 1;
		while (i < arr.size())
		{
			if (arr[i].check == true)
				n1 += arr[i].num;
			else
				n2 += arr[i].num;
			i++;
		}
		if (n1 == n2) 
		{
			cout << "YES" << endl;
			exit(0);
		}
		return;
	}

	arr[depth].check = true;	
	dfs(depth + 1, arr);
	arr[depth].check = false;
	dfs(depth + 1, arr);
}


int main(void)
{
    //freopen("input.txt", "rt", stdin);
	int n;
	cin >> n;

	vector<element> arr(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> arr[i].num;
		arr[i].check = false;
	}

	dfs(1, arr);
	cout << "NO" << endl;

    return 0;
}
