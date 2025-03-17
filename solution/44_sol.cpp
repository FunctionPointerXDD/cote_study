/**
 * 44. 마구간 정하기(이분검색 응용)
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int _count(std::vector<int> &arr, int min, int n, int c)
{
	int cnt = c - 1;
	int pivot = 0; //처음 배치할 마구간의 인덱스
	//pivot은 항상 첫번째 마구간에 배치하는 것이 옳다!

	for (int j = pivot + 1; j < n; ++j)
	{
		int dist = arr[j] - arr[pivot];
		if (dist >= min)
		{
			pivot = j;
			cnt--;
		}
		if (cnt <= 0)
			break;
	}
	return cnt;
}

int main(void)
{
    //freopen("input.txt", "rt", stdin);
	int n, c;
	cin >> n >> c;

	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	sort(arr.begin(), arr.end());

	int lt = arr[0];
	int rt = arr[n - 1];
	int min;
	int res;

	while (lt <= rt)
	{
		// min은 기대하는 가장 가까운 두 말의 최대  거리
		min = (lt + rt) / 2;

		if (_count(arr, min, n, c) == 0)
		{
			res = min;
			lt = min + 1;
		}
		else
			rt = min - 1;
	}

	cout << res << endl;	
	
	return 0;
}
