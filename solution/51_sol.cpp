/**
 * 51. 영지(territory) 선택 : (large)
 * dynamic programming -> 영지의 숫자를 받을 때, 원점으로 부터 해당 좌표까지 면적의 합을 구해서 입력받는다.
 * 그런 뒤 특정 영지 구역의 합을 구할 때는, 해당 좌표로 부터 가로, 세로 거리 전에 위치한 누적 값을 빼준뒤, 중복해서 빼준 부분인 가로 세로 이전의 위치한 누적값을 더해준다.
 * 이렇게 하면 2중 for문으로 해결이 가능하다.
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

	vector<vector<int> > map(n + 1, vector<int> (m + 1));

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> map[i][j];
			map[i][j] += (map[i][j - 1] + map[i - 1][j] - map[i - 1][j - 1]);
		}
	}

	int h, w;
	cin >> h >> w;

	int sum;
	int max = -2147483648;

	for (int i = h; i <= n; ++i)
	{
		for (int j = w; j <= m; ++j)
		{
			sum = map[i][j] - map[i][j - w] - map[i - h][j] + map[i - h][j - w];
			if (max < sum)
				max = sum;
		}
	}

	cout << max << endl;
	return 0;
}
