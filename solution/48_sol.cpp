/**
 * 48. 각 행의 평균과 가장 가까운 값
 */
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


int main(void)
{
	freopen("input.txt", "rt", stdin);	

	vector<vector<int> > map(81, vector<int>(81));
	vector<int> avg(9);

	double sum;
	for (int i = 0; i < 9; ++i)
	{
		sum = 0.0;
		for (int j = 0; j < 9; ++j)
		{
			cin >> map[i][j];
			sum += map[i][j];
		}
		avg[i] = round(sum / 9.0);
	}

	double min, dist;
	int idx;
	for (int i = 0; i < 9; ++i)
	{
		min = 10000;
		idx = -1;
		for (int j = 0; j < 9; ++j)
		{
			dist = abs(avg[i] - map[i][j]);
			if (min > dist)
			{
				min = dist;
				idx = j;
			}
			else if (min == dist)
			{
				if ((avg[i] - map[i][j]) > 0)
					min = dist;
			}
		}
		cout << avg[i] << ' ' << map[i][idx] << '\n';
	}

	return 0;
}
