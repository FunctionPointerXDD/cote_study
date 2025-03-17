/**
 * 43. 뮤직비디오 (이분검색 응용) -> 결정 알고리즘
 * 최대로 녹화 가능한 값은 전체 시간의 합이다. 
 * 가장 작은 녹화 시간과 최대 녹화 가능한 값 사이에서 이분 검색으로 
 * 최소 용량 크기를 찾으면 된다.
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int _count(int mid, int n, std::vector<int> &time_len)
{
	int sum = 0;
	int cnt = 1; // 분할 되서 계산 되기 때문에 +1로 시작한다.
	for (int i = 0; i < n; ++i)
	{
		if (sum + time_len[i] > mid)
		{
			sum = time_len[i];
			cnt++;
		}
		else
			sum += time_len[i];
	}
	return cnt;
}


int main(void)
{
    //freopen("input.txt", "rt", stdin);
	int n, m;
	int low, high, mid;
	int res;

	cin >> n >> m;

	vector<int> time_len(n);

	int max = -2147483648;
	high = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> time_len[i];
		high += time_len[i];
		if (max < time_len[i])
			max = time_len[i];
	}
	low = time_len[0];

	while (low <= high)	
	{
		mid = (low + high) / 2;

		if (mid >= max && _count(mid, n, time_len) <= m)
		{
			res = mid;
			high = mid - 1;
		}
		else
			low = mid + 1;
	}

	cout << res << endl;
	
	return 0;
}
