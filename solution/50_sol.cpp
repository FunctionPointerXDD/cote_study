/**
 * 50. 영지(territory) 선택 : (small)
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main(void)
{
	//freopen("input.txt", "rt", stdin);	

	int n, m;
	cin >> n >> m;

	vector<vector<int> > map(n, vector<int> (m));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			cin >> map[i][j];
	}

	int h, w;
	cin >> h >> w;

	int sum;
	int max = -2147483648;

	for (int i = 0; i <= n - h; ++i)
	{
		for (int j = 0; j <= m - w; ++j)
		{
			sum = 0;
			for (int k = i; k < i + h; ++k)
			{
				for (int l = j; l < j + w; ++l)
					sum += map[k][l];
			}
			if (max < sum)
				max = sum;
		}
	}

	cout << max << endl;
	return 0;
}
