/**
 * 46. 멀티태스킹(카카오 먹방 문제 변형) -> 라운드 로빈 (1초 단위로 태스크 수행)
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    //freopen("input.txt", "rt", stdin);
	int n, k;
	int task = 0;

	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		task += arr[i];
	}
	cin >> k;

	if (task <= k)
	{
		cout << -1 << endl;
		return 0;
	}

	int t = -1; //t가 k가 되었을때 시간을 구하려면 -1부터 시작해야 정확하다. 
	int pos = 0;
	while (1)
	{
		pos = pos % n;
		if (arr[pos] > 0)
		{
			arr[pos]--;
			t++;
			if (t == k) // 이 시점에서 if(arr[pos] > 0)문 안에 계산은 정전때문에 이루어질 수 없는 계산이다.
				break;
		}
		pos++;
	}

	cout << pos + 1 << endl;

	return 0;
}
