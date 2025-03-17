/**
 * 49. 블록의 최댓값
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main(void)
{
	//freopen("input.txt", "rt", stdin);	

	int n;
	cin >> n;

	vector<vector<int> > map(n, vector<int> (n));

	vector<int> front(n);
	vector<int> right(n);

	for (int i = 0; i < n; ++i)
		cin >> front[i];
	for (int i = 0; i < n; ++i)
		cin >> right[i];

		
	// front에서 보이는 것으로 열부터 전부 채워준다.
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			map[j][i] = front[i];
	}

	// 행부터 순서대로 이전의 입력된 값과 right에서 보이는 최대값을 비교해서 큰 경우, right에서 보이는 크기로 변경한다.
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (map[i][j] > right[n - 1 - i])
				map[i][j] = right[n - 1 - i];
		}
	}


	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			cnt += map[i][j];
	}

	cout << cnt << endl;

	return 0;
}
